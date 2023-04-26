#!/bin/bash
#SBATCH --job-name=DNA
#SBATCH --time=2:0:0
#SBATCH --nodes=96
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1

#SBATCH --partition=highmem
#SBATCH --qos=highmem
#SBATCH --account=z19

module load cpe/22.04
module load PrgEnv-gnu
module load cray-fftw
export $LD_LIBRARY_PATH=$CRAY_LD_LIBRARY_PATH:$LD_LIBRARY_PATH


CASTEP_EXE="/work/y07/shared/apps/core/castep/22.11/bin/castep.mpi"

ldd $(which $CASTEP_EXE)

nodes=$SLURM_JOB_NUM_NODES
casename="polyA20-no-wat"
cpn=128
threads=1
smp=16

export SLURM_CPU_FREQ_REQ=2250000

cores=$(( nodes * cpn ))
timestamp=$(date '+%Y%m%d%H%M')

resfile="${casename}_${nodes}nodes_${cores}cores_${threads}threads_${smp}smp_${SLURM_CPU_FREQ_REQ}freq_${SLURM_JOB_ID}_${timestamp}.castep"
TMPDIR=$PWD
export OMP_NUM_THREADS=${threads}
export OMP_PLACES=cores

uuid=$(uuidgen)
workdir=${uuid}-workdir

mkdir $workdir
cd $workdir

cp ../${casename}.param.base ${casename}.param
echo "num_proc_in_smp   : ${smp}" >> ${casename}.param

cp ../*.recpot .
cp ../${casename}.cell .

srun --hint=nomultithread --distribution=block:block $CASTEP_EXE ${casename}
sleep 30

mv ${casename}.castep ../${resfile}
cd ..
rm -r $workdir

sleep 120
echo "\n++Energy use:" >> $resfile
sacct -j $SLURM_JOB_ID --format="JobID,NNodes,NTasks,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" >> $resfile


