#!/bin/bash

#SBATCH --job-name=LMP_ethanol
#SBATCH --nodes=4
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1
#SBATCH --time=2:0:0

#SBATCH --account=z19
#SBATCH --partition=standard
#SBATCH --qos=standard

module load lammps/17_Feb_2023

export OMP_NUM_THREADS=1

casename="ethanol"
srunopts="--hint=nomultithread --distribution=block:block"

freqs="2000000"

for freq in $freqs
do
   timestamp=$(date '+%Y%m%d%H%M')
   resfile=${casename}_${SLURM_JOB_NUM_NODES}nodes_${freq}freq_${SLURM_JOBID}_${timestamp}.log
   rm ${casename}.check
   export SLURM_CPU_FREQ_REQ=$freq
   echo "SLURM_CPU_FREQ_REQ=$freq"
   srun ${srunopts} lmp -in in.ethanol_optimized -l ${resfile} &
   sleep 30
done

echo $HOSTNAME
for i in $(seq 3000)
do
a=$(cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq)
b=$(cat /sys/cray/pm_counters/cpu_power)
echo $i $a $b >> freq-${SLURM_JOBID}.out
sleep 60
done

wait

sleep 300

sacct -j $SLURM_JOB_ID --format="JobID,NodeList,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw" > energy_${SLURM_JOB_ID}.dat

