#!/bin/bash

# Slurm job options (job-name, compute nodes, job time)
#SBATCH --job-name=AIMS-bench
#SBATCH --time=12:0:0
#SBATCH --nodes=16
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1

# Replace [budget code] below with your budget code (e.g. t01)
#SBATCH --account=z19
#SBATCH --partition=standard
#SBATCH --qos=standard

# Load compilation time environment
module load fhiaims
# module load craype-network-ucx
# module load cray-mpich-ucx
# export LD_LIBRARY_PATH=$CRAY_LD_LIBRARY_PATH:$LD_LIBRARY_PATH

# Set the number of threads to 1
#   This prevents any threaded system libraries from automatically
#   using threading.
export OMP_NUM_THREADS=1

casename="Ti-MOF"

freqs="2000000 2250000"

for freq in $freqs
do
   timestamp=$(date '+%Y%m%d%H%M')
   resfile=${casename}_${SLURM_JOB_NUM_NODES}nodes_${freq}freq_${SLURM_JOBID}_${timestamp}.log
   export SLURM_CPU_FREQ_REQ=$freq
   echo "SLURM_CPU_FREQ_REQ=$freq"
   srun ${srunopts} aims.mpi.x > ${resfile}
   sleep 30
done

sleep 300

sacct -j $SLURM_JOB_ID --format="JobID,NodeList,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" > energy_${SLURM_JOB_ID}.dat

