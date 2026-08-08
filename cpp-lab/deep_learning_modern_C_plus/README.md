# Deep Learning in Modern C++ — study course

Working through **_Deep Learning in Modern C++_** (Luiz Carlos d'Oleron, BPB, 2025)
as a modern-C++ side track: read a chapter, then write my **own** implementation
in that chapter's folder (book code is **not** copied here).

Book repo (reference only): https://github.com/bpbpublications/Deep-Learning-in-Modern-C-Plus-Plus

## Why this book

It teaches modern C++ (templates, move semantics, RAII, Eigen) *through* building
deep learning from scratch — and it **ends exactly at my target job's domain**:
CV models → image classifier → transfer learning → **object localization
(≈ detection = drone detection)**. Learning C++ here directly grows the skill ACS
CV/ML wants.

## Goal: ~1 chapter/day

Dense chapters (Convolutions, Backpropagation, Optimizers) may take 2 days — that's
fine. Chapters 14–17 feed the CV/Jetson project directly, so slow down and milk them.

## Progress

- [ ] **Ch 01** — Introduction to Deep Learning Programming *(read-only, no code folder)*
- [ ] **Ch 02** — Coding Deep Learning with Modern C++  → C++ setup, Eigen, value/move semantics
- [ ] **Ch 03** — Testing Deep Learning Code  → unit testing habits
- [ ] **Ch 04** — Implementing Convolutions  → the core CV op
- [ ] **Ch 05** — Coding the Fully Connected Layer  → classes/templates
- [ ] **Ch 06** — Learning by Minimizing Cost Functions
- [ ] **Ch 07** — Defining Activation Functions
- [ ] **Ch 08** — Using Pooling Layers
- [ ] **Ch 09** — Coding the Gradient Descent Algorithm
- [ ] **Ch 10** — Coding the Backpropagation Algorithm  → ⭐ the big one (autograd)
- [ ] **Ch 11** — Underfitting, Overfitting, and Regularization
- [ ] **Ch 12** — Cross-validation, Mini Batching, and Model Performance Metrics
- [ ] **Ch 13** — Implementing Optimizers  → SGD, Adam
- [ ] **Ch 14** — Introducing Computer Vision Models  → 🎯 ACS territory begins
- [ ] **Ch 15** — Developing an Image Classifier  → 🎯
- [ ] **Ch 16** — Leveraging Training Performance with Transfer Learning  → 🎯
- [ ] **Ch 17** — Developing an Object Localization System  → 🎯 ≈ drone detection

## How I use this

- One folder per chapter (`Chapter 02` … `Chapter 17`), matching the book repo's names.
- I write my **own** code/notes in each folder as I go — no copying from the book repo.
- Each chapter is a small "assignment"; the CV chapters (14–17) tie into the
  Jetson drone-detection project.
