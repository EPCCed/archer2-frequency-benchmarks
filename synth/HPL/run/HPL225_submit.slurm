#!/bin/bash

# Slurm job options (job-name, compute nodes, job time)
#SBATCH --job-name=HPL_2.25GHz
#SBATCH --time=12:0:0
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=128
#SBATCH --cpus-per-task=1

# Replace [budget code] below with your budget code (e.g. t01)
#SBATCH --account=z19 
#SBATCH --partition=standard
#SBATCH --qos=standard

# Set the number of threads to 1
#   This prevents any threaded system libraries from automatically 
#   using threading.
export OMP_NUM_THREADS=1

timestamp=$(date '+%Y%m%d%H%M')
energyfile=energy.225GHz.${timestamp}
outputfile=output.225GHz.${timestamp}

srun --distribution=block:block --hint=nomultithread --cpu-freq=2250000 hpl-2.3/bin/ARCHER2/xhpl > ${outputfile} 2> stderr225.txt


sleep 120
echo "\n++Energy use:" >> ${energyfile}
sacct -j $SLURM_JOB_ID --format="JobID,NNodes,NTasks,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" >> ${energyfile}

mv ${energyfile} outputs
mv ${outputfile} outputs
