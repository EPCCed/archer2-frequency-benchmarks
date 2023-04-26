#!/bin/bash
#SBATCH --job-name=TGV1024ss_225G
#SBATCH --time=3:0:0
#SBATCH --nodes=128
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1

#SBATCH --partition=standard
#SBATCH --qos=standard
#SBATCH --account=z19

module load cpe/22.04
module load cray-hdf5-parallel
export LD_LIBRARY_PATH=$CRAY_LD_LIBRARY_PATH:$LD_LIBRARY_PATH

freq=2000000
osblipath="/work/z19/z19/shared/ARCHER2_CSF/OpenSBLI/source/Benchmark"
srun_opts="--unbuffered --hint=nomultithread --distribution=block:block --cpu-freq=${freq}"

ldd ${osblipath}/OpenSBLI_mpi_openmp

cp input.small input

nodes=$SLURM_JOB_NUM_NODES
casename="TGV1024ss"
cpn=128
cores=$(( nodes * cpn ))

timestamp=$(date '+%Y%m%d%H%M')
resfile="${casename}_${nodes}nodes_${freq}freq_${SLURM_JOB_ID}_${timestamp}.out"
TMPDIR=$PWD
export OMP_NUM_THREADS=1
srun ${srun_opts} ${osblipath}/OpenSBLI_mpi_openmp > $resfile

sleep 120
echo "\n++Energy use:" >> $resfile
sacct -j $SLURM_JOB_ID --format="JobID,NNodes,NTasks,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" >> $resfile

