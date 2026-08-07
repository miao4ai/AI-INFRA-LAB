# Pi Cluster — 4-node Slurm on Raspberry Pi

A bare-metal ARM64 HPC cluster built on 4 Raspberry Pis running Ubuntu Server.
It provides the orchestration + CPU-distributed foundation reused by the
benchmarking studies in this repo (`../gpu-scaling-study`, `../hpc-app-benchmark`).

## Architecture

```
            node00  (head/login)   slurmctld + NFS server + munge
               │  Ethernet switch (wired)
    ┌──────────┼──────────┐
  node01     node02     node03      compute nodes: slurmd
```

- **OS**: Ubuntu Server 24.04 LTS (arm64)
- **Auth**: munge (shared key across all nodes)
- **Shared storage**: NFS export from node00 → `/shared` on every node
- **Scheduler**: Slurm (`slurmctld` on head, `slurmd` on all)

> GPU workloads (TensorRT, distributed GPU training) do **not** run here — the
> Pis have no NVIDIA GPU. This cluster handles orchestration, CPU-distributed
> jobs, MPI, and containers. GPU benchmarking happens on cloud x86_64 instances.

## Node inventory

| Node   | Role          | IP (fill in) |
| ------ | ------------- | ------------ |
| node00 | head / login  | 192.168._._  |
| node01 | compute       | 192.168._._  |
| node02 | compute       | 192.168._._  |
| node03 | compute       | 192.168._._  |

## Build checklist

- [x] **Day 1** — Flash Ubuntu Server 24.04 (arm64) to 4 SD cards; all nodes SSH-reachable
- [ ] **Day 2** — `/etc/hosts` on all nodes; passwordless SSH from head; NFS `/shared`; install Apptainer
- [ ] **Day 3** — munge auth (generate key on head, distribute); install Slurm
- [ ] **Day 4** — write `slurm.conf` (4 nodes + partition); start services; `sinfo` shows 4 idle nodes
- [ ] **Day 5** — submit jobs with `sbatch` / `srun -N4`; run a containerized job; document results

## Build log

_(Record commands, errors, and fixes here as you go — this becomes source
material for the benchmark report.)_

### Day 1
- Flashed Ubuntu Server 24.04 arm64 via Raspberry Pi Imager (hostnames node00–node03).
- All four nodes online and SSH-reachable.
