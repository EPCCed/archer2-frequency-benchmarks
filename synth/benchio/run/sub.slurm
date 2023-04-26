#!/bin/bash

# Slurm job options (name, compute nodes, job time)
#SBATCH --job-name=benchio
#SBATCH --time=00:20:00
#SBATCH --nodes=1
#SBATCH --tasks-per-node=128
#SBATCH --cpus-per-task=1
# Replace [budget code] below with your budget code (e.g. t01)
#SBATCH --account=z19
#SBATCH --partition=standard
#SBATCH --qos=short

cat $0

module swap craype-network-ofi craype-network-ucx
module swap cray-mpich cray-mpich-ucx

module use /work/z19/shared/sfarr/modulefiles
module load adios/2.8.3

module load cray-hdf5-parallel
module load cray-netcdf-hdf5parallel

export OMP_NUM_THREADS=1

ulimit -s unlimited

# Launch the parallel job

export FI_OFI_RXM_SAR_LIMIT=64K
export MPICH_MPIIO_HINTS=*:cray_cb_write_lock_mode=0,*:cray_cb_nodes_multiplier=1

srun --unbuffered --distribution=block:block --hint=nomultithread \
	/work/z19/z19/shared/ARCHER2_CSF/benchio/benchio/benchio 2048 2048 2048 global mpiio adios

sleep 120
echo "\n++Energy use:"
sacct -j $SLURM_JOB_ID --format="JobID,NNodes,NTasks,ReqCPUFreq,ElapsedRaw,ConsumedEnergyRaw"

