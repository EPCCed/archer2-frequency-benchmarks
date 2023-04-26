#!/bin/bash
#SBATCH --job-name=CASTEP_al3x3
#SBATCH --nodes=1
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

freqs="1500000 2000000 2250000"

for freq in $freqs
do
   timestamp=$(date '+%Y%m%d%H%M')
   resfile=${casename}_${SLURM_JOB_NUM_NODES}nodes_${freq}freq_${SLURM_JOBID}_${timestamp}.castep
   rm ${casename}.check
   srun ${srunopts} --cpu-freq=${freq} $CASTEP_EXE $casename
   sleep 30
   mv ${casename}.castep ${resfile}
done

sleep 300

sacct -j $SLURM_JOB_ID --format="JobID,NodeList,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" > energy_${SLURM_JOB_ID}.dat

# sbatch submit_1node.slurm
