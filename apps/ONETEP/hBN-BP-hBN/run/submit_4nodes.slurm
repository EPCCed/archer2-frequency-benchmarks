#!/bin/bash

#SBATCH --job-name=ONETEP-hBN-test
#SBATCH --partition=standard
#SBATCH --qos=standard
#SBATCH --nodes=4
#SBATCH --ntasks-per-node 16
#SBATCH --cpus-per-task 8
#SBATCH --time=6:0:0

#SBATCH --account=z19

module load onetep

casename="hBN-BP-hBN"
nodes=$SLURM_JOB_NUM_NODES
omp_threads_per_mpi_rank=$SLURM_CPUS_PER_TASK
srunopts="--hint=nomultithread --distribution=block:block"

freqs="2000000 2250000"

for freq in $freqs
do
   timestamp=$(date '+%Y%m%d%H%M')
   resfile=${casename}_${SLURM_JOB_NUM_NODES}nodes_${freq}freq_${SLURM_JOBID}_${timestamp}.log
   export SLURM_CPU_FREQ_REQ=$freq
   echo "SLURM_CPU_FREQ_REQ=$freq"
   srun ${srunopts} onetep_launcher -e onetep.archer2 -t $omp_threads_per_mpi_rank ${casename}.dat >${resfile} 
   sleep 30
done

sleep 300

sacct -j $SLURM_JOB_ID --format="JobID,NodeList,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" > energy_${SLURM_JOB_ID}.dat


