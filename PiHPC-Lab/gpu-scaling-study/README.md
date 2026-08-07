# GPU Scaling Study — Distributed Training & TensorRT Inference

A cost/performance benchmarking study for image workloads, from distributed
training on a Slurm cluster to optimized inference with TensorRT.

## The question this study answers

> **To classify/detect objects in images at a target throughput, what is the
> cheapest hardware + software configuration — and at how many GPUs does adding
> more stop paying off?**

## Two parts

### Part A — Distributed training scaling (Slurm + PyTorch DDP)
- **Model**: ResNet-50 (→ upgrade to YOLOv8 for object detection later)
- **Data**: Imagenette (10-class ImageNet subset, fast.ai) — real images, small enough to iterate cheaply
- **Measure**: images/sec, scaling efficiency (1→2→4 GPUs), time-to-accuracy, GPU utilization, $/epoch
- **How**: Apptainer container launched via Slurm `sbatch` + `torchrun`

### Part B — Inference optimization & benchmark (TensorRT)
- Export trained model → ONNX → TensorRT engine (FP32 / FP16 / INT8, INT8 with calibration data)
- **Measure**: latency (p50/p99), throughput, accuracy drop, $/1M images
- **Across**: instance types (T4 vs A10 vs A100)

## Deliverable

`REPORT.md` — methodology, scaling curves, speedup tables, cost analysis, and a
clear recommendation. Fully reproducible: scripts + Slurm batch files +
Apptainer defs live in this folder.

## Layout

```
gpu-scaling-study/
├── train/        # DDP training scripts + Slurm batch files
├── inference/    # ONNX export, TensorRT build, latency/throughput benchmarks
├── results/      # raw numbers, plots
└── REPORT.md     # the deliverable (written last)
```

## Infrastructure

- **Orchestration / CPU-distributed**: the Pi Slurm cluster (`../cluster`)
- **GPU training + TensorRT**: cloud x86_64 GPU instances (spot/preemptible, ~$100 budget)
