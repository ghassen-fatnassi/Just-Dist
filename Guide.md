# Just-Dist

A minimal, thread-aware C++ project simulating and benchmarking industry-grade **all-reduce** algorithms and **parallel training strategies** like **data parallelism** and **pipeline parallelism**, using `libtorch` tensors for realism.

---

## 💡 Project Vision

Simulate how distributed systems perform **tensor communication** and **model parallel training**, like real-world LLM and DNN frameworks (e.g. Megatron, DeepSpeed, PipeDream, etc.).  
The goal is **not** to do actual distributed compute, but to model and analyze it realistically using threads, message-passing, and CPU-based tensor operations.

---

## 🧱 Architecture Overview

```
[ Node0 ] ─────┐
[ Node1 ] ───┐ │   --> Simulated topology (ring/tree/etc.)
[ Node2 ] ─┐ │ │
    ...    ↓ ↓ ↓
[ CommBus / AllReduceAlgo ] <--- implements algorithm over N nodes
[ Scheduler ] <-- executes simulated forward/backward passes
[ Timer/Logger ] <-- logs performance per iteration
```

---

## ⚙️ System Requirements

- Ubuntu 20.04+
- `libtorch` (C++ PyTorch) — CPU as a start , GPU next
- `g++` 9+ (C++17 or later)
- `CMake` 3.18+

---

## 🏗️ Project Setup

1. **Clone the repo**

```bash
git clone https://github.com/yourname/Just-Dist.git
cd Just-Dist
```

2. **Download libtorch** CPU version:
   https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.7.1.zip
   Unzip to `Just-Dist/libtorch/`.

3. **Build the project**

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
./just_dist
```

---

## 🧩 Implementation Order

### 📍 Phase 1: Core Infrastructure
* ✅ `main.cpp` for bootstrapping
* ✅ Setup `CMakeLists.txt`
* ✅ Define `Node` struct/class (represents one device)
* ✅ Implement simple `RingAllReduce` with threads + tensor addition
* ✅ Write benchmarking wrapper using `std::chrono`

### 📍 Phase 2: All-Reduce Algorithms
* Ring All-Reduce (`comm/ring_allreduce.cpp`)
* Tree All-Reduce
* Halving-Doubling
* Butterfly
* Compare latency vs #nodes, tensor size

### 📍 Phase 3: Scheduler & Pipeline Sim
* Implement forward-backward pipeline (e.g. 4-layer toy model)
* Each layer = thread on a node with delay
* Use condition variables or semaphores to simulate stage dependencies

### 📍 Phase 4: Benchmark & Logging
* Write JSON/CSV logs: `{algo, time, num_nodes, tensor_shape}`
* Visualize later with matplotlib or JS timeline

### 📍 Phase 5 (Optional): Fancy
* Simulate bandwidth caps & latency
* Use profiler macros like `PROFILE_SCOPE("ring_reduce")`
* Plug in real GPU + CUDA later if needed

---

## 📦 Folder Structure

```
Just-Dist/
├── CMakeLists.txt
├── include/
│   └── just_dist/             # public headers
├── src/
│   ├── main.cpp
│   ├── comm/                  # allreduce algorithms
│   └── scheduler/             # pipeline/data-parallel scheduling
├── libtorch/                  # external lib (not committed)
├── build/                     # cmake build dir
└── README.md
```

---

## 📜 License

MIT — use, fork, learn, modify freely.

## 🙋‍♂️ Author

Ghassen Fatnassi — cracking distributed AI one thread at a time.