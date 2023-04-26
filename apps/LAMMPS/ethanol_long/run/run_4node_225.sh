#!/bin/bash

#sBATCH --job-name=4nodes_225ghz
#SBATCH --nodes=4
#SBATCH --exclusive
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1
#SBATCH --time=1:00:00

#SBATCH --account=z19
#SBATCH --partition=standard
#SBATCH --qos=standard
#SBATCH --distribution=block:block
#SBATCH --hint=nomultithread

CPU_FREQ=2250000

module load lammps/17_Feb_2023

#module list

# Set the number of threads to 1
export OMP_NUM_THREADS=1

# Launch the parallel job
srun --cpu-freq=$CPU_FREQ lmp -in in.ethanol_optimized -l log.${CPU_FREQ}.${SLURM_JOB_ID}

#sleep 120
#echo "++Energy use:" > energy_${SLURM_JOB_ID}.dat
#sacct -j $SLURM_JOB_ID --format="JobID,NNodes,NTasks,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" >> energy_${SLURM_JOB_ID}.dat
