#!/bin/bash

#SBATCH --time=0:10:0
#SBATCH --nodes=3
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1
#SBATCH --account=z19
#SBATCH --partition=standard
#SBATCH --qos=short
#SBATCH --hint=nomultithread
#SBATCH --distribution=block:block

module load gromacs/2022.4
export OMP_NUM_THREADS=1

#export SLURM_CPU_FREQ_REQ=2000000

srun gmx_mpi mdrun -ntomp 1 --noconfout -s ../../benchmark.tpr

sleep 120
echo "\n++Energy use:" >> md.log
sacct -j $SLURM_JOB_ID --format="JobID,NNodes,NTasks,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" >> md.log

