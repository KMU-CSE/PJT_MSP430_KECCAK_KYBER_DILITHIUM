# Optimized Implementations of Keccak, Kyber, and Dilithium on the MSP430 Microcontroller
- Title: **Optimized Implementations of Keccak, Kyber, and Dilithium on the MSP430 Microcontroller**
- Authors: DongHyun Shin, YoungBeom Kim, Ayesha Khalid, Máire O’Neill2 and Seog Chung Se

## Artifact
This repository contains the **artifact** accompanying our paper accepted in [**CHES 2026**](https://ches.iacr.org/2026/) issue 2.
It includes the complete source code, MSP430 assembly implementations for **Keccak**, **Kyber**, and **Dilithium**.
This repository contains two subfolders:

```bash
repos/
├── README.md
├── Kyber/
│   ├── opt/
│   └── ref/
└── Dilithium/
    ├── opt/
    └── ref/
```

The artifact demonstrates:
- **Optimized implementations** of Kyber and Dilithium on 16-bit MSP430 microcontrollers.
    -  The Keccak implementation can be found within each scheme.
- **Optimized MSP430 assembly routines** for modular arithmetic, NTT, inverse NTT, and Keccak.  
- **Experimental results** including cycle counts, stack usage, and code size, validated on the `MSP430F67791` device.

All materials are provided to ensure **reproducibility**, **transparency**, and **practical validation** of our results for the [CHES 2026 artifact evaluation](https://ches.iacr.org/2026/artifacts.php).

## Abstract

Post-Quantum Cryptography (PQC) demands greater memory and computational resources than conventional public-key schemes. While most optimization studies have targeted 32- and 64-bit ARM architectures, research on lower-end devices remains limited. This work presents the first optimized implementations of CRYSTALS-Kyber and CRYSTALS-Dilithium on the 16-bit MSP430 microcontroller.

Our contributions are summarized as follows:

1. **Optimized Keccak Implementation methodology.**  
- Despite Keccak’s widespread use in cryptographic primitives, no publicly available implementation exists for the 16-bit MSP430 architecture, not even in the official eXtended Keccak Code Package (XKCP).  
- This gap underscores the challenge of realizing standardized algorithms on ultra-constrained platforms.  
- Since the 16-bit MSP430 architecture has limited registers, small SRAM, and lacks efficient bitwise instruction, existing ARM- or AVX2-oriented optimization techniques are unsuitable.  
- After thoroughly reviewing existing optimization techniques for Keccak, we conclude that existing methods are not well-suited for MSP430.  
- To address this, we propose two novel techniques: the twisting technique, which minimizes memory access cost, and the zig-zag technique, which improves computational efficiency.  
- Our Keccak implementation, which is the first reported implementation on MSP430, achieves approximately 57% performance improvement over the C reference, setting a new speed record.  

2. **Optimized NTT implementation methodologies.**  
- We redefine the NTT implementation strategy to align with the register structure and instruction set of the 16-bit MSP430 architecture.  
- To maximize the use of the memory-mapped dedicated hardware multiplier, we propose a schoolbook-based lazy reduction technique for the point-wise multiplication step.  
- Additionally, we revisit the merging strategy and modular multiplication methods to better suit the characteristics of the MSP430 platform.  
- As a result, compared with the reference implementations in C, the optimized 16-bit NTT achieves performance improvements of 134%, 249%, and 210% for NTT, NTT⁻¹, and point-wise multiplication, respectively, while the optimized 32-bit NTT achieves 74%, 80%, and 56% improvements, respectively.  
- Regarding the proposed reduction methods, different from the previously proposed modular reduction methods on 8-bit AVR and 16-bit MSP430 MCUs from prior works, they can be easily applied to other 16-bit MCUs with similar architectural properties because they are based on generic signed Montgomery and Barrett reduction methods.  

3. **Optimized Kyber and Dilithium implementations on MSP430.**  
- We present the optimized MSP430 implementations of Kyber and Dilithium supporting all security levels, enabled by our integrated Keccak and NTT optimizations.  
- As a result, compared to the C reference Kyber implementation, we achieve performance improvements of 46.1–51.3%, 45.6–60.0%, and 46.2–62.3% for the Keygen, Encaps, and Decaps of Kyber at all security levels.  
- For Dilithium, we achieve performance improvements of 44.5–48.3%, 57.5–65.0%, and 46.1–50.0% for Keygen, Sign, and Verify, respectively.  

## Benchmark Setup
We developed and benchmarked the code using the "IAR Embedded Workbench for MSP430" IDE (https://www.iar.com/embedded-development-tools). For testing purposes, the IAR IDE offers a free trial version.

Please select “New Workspace” and “New Project” in IAR Workbench and paste our code.
The target device is "MSP430F67791", equipped with 32KB of RAM.
The compiler used is "IAR C/C++ Compiler for MSP430 (version 8.10.3)", and we compile the code using the "High (Speed)" option, which is equivalent to the “-O3” option in GCC.
Our Kyber and Dilithium implementations are based on the optimized code from PQClean (https://github.com/PQClean/PQClean).
- In *Tools* → *Options* → *stack*, we enabled the flag `Enable stack usage tracking`, and measured stack usage via *View* → *stack* during runtime.
- We measure cycle counts using the \texttt{CYCLECOUNTER} register in *View* → *registers*.
- We measured code size from the *.map* file generated after the build.
- Note: Code execution may take a long time. Please wait—this is expected behavior and not a bug.
