#!/bin/bash
#SBATCH --job-name=CASTEP_al3x3
#SBATCH --nodes=4
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1
#SBATCH --time=2:0:0
#SBATCH --account=z19
#SBATCH --partition=standard
#SBATCH --qos=standard

module load castep/21.11

CASTEP_EXE=castep.mpi

casename="al3x3"
srunopts="--hint=nomultithread --distribution=block:block"
TMPDIR=$PWD
export OMP_NUM_THREADS=1

timestamp=$(date '+%Y%m%d%H%M')
resfile=${casename}_${SLURM_JOB_NUM_NODES}nodes_${freq}freq_${SLURM_JOBID}_${timestamp}.castep
rm ${casename}.check
echo "SLURM_CPU_FREQ_REQ=$SLURM_CPU_FREQ_REQ"
echo "CPUINFO FREQ:"
srun --ntasks=1 --nodes=1 --tasks-per-node=1 ${srunopts} cat /proc/cpuinfo | grep MHz | head -n1
echo "CPUINFO FREQ (--cpu-freq):"
srun --ntasks=1 --nodes=1 --tasks-per-node=1 --cpu-freq=2250000 ${srunopts} cat /proc/cpuinfo | grep MHz | head -n1
echo "CPUINFO FREQ (reset VAR):"
export SLURM_CPU_FREQ_REQ=2250000
srun --ntasks=1 --nodes=1 --tasks-per-node=1 ${srunopts} cat /proc/cpuinfo | grep MHz | head -n1
srun ${srunopts} $CASTEP_EXE $casename
sleep 30
mv ${casename}.castep ${resfile}

sleep 300

sacct -j $SLURM_JOB_ID --format="JobID,NodeList,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" > energy_${SLURM_JOB_ID}.dat


