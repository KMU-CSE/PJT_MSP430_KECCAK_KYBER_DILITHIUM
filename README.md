# Optimized Implementations of Keccak, Kyber, and Dilithium on the MSP430 Microcontroller
- Title: **Optimized Implementations of Keccak, Kyber, and Dilithium on the MSP430 Microcontroller**
- Authors: DongHyun Shin, YoungBeom Kim, Ayesha Khalid, Máire O’Neill and Seog Chung Seo

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
- As a result, compared with the reference implementations in C, the optimized 16-bit NTT achieves performance improvements of 134%, 249%, and 210% for NTT, NTT⁻¹, and point-wise multiplication, respectively, while the optimized 32-bit NTT achieves 91%, 96%, and 56% improvements, respectively.  
- Regarding the proposed reduction methods, different from the previously proposed modular reduction methods on 8-bit AVR and 16-bit MSP430 MCUs from prior works, they can be easily applied to other 16-bit MCUs with similar architectural properties because they are based on generic signed Montgomery and Barrett reduction methods.  

3. **Optimized Kyber and Dilithium implementations on MSP430.**  
- We present the optimized MSP430 implementations of Kyber and Dilithium supporting all security levels, enabled by our integrated Keccak and NTT optimizations.  
- As a result, compared to the C reference Kyber implementation, we achieve performance improvements of 46.1–51.3%, 45.6–60.0%, and 46.2–62.3% for the Keygen, Encaps, and Decaps of Kyber at all security levels.  
- For Dilithium, we achieve performance improvements of 44.5–48.3%, 57.5–65.0%, and 46.1–50.0% for Keygen, Sign, and Verify, respectively.  

## Benchmark Setup
We developed and benchmarked the code using the "IAR Embedded Workbench for MSP430" IDE (https://www.iar.com/embedded-development-tools). For testing purposes, the IAR IDE offers a free trial version.

Please select “New Workspace” and “New Project” in IAR Workbench and paste our code.
The target device is "MSP430F67791", equipped with 32KB of RAM.
The compiler used is "IAR C/C++ Compiler for MSP430 (version 8.10.3)", and we compile the code using the "High (Speed)" option.

- Note: Code execution may take a long time. Please wait—this is expected behavior and not a bug.
  
### 1. Cycle Measurement

Cycle counts are measured using the `CYCLECOUNTER` or `CCSTEP` registers.

- Set a breakpoint at the target function (e.g., `kem_keypair`, `kem_enc`) and run the project.
- During execution, enable **View → Registers** to monitor the `CYCLECOUNTER` or `CCSTEP` registers.
  - `CYCLECOUNTER`: cumulative cycle count
  - `CCSTEP`: cycle count for the currently executed function

---

### 2. Stack Usage Measurement

To measure stack usage, enable the following options:

- **Tools → Options → Stack**
  - Enable `Enable stack usage tracking`
- **Project Options → General Options → Stack/Heap**
  - Increase the maximum stack observation range if necessary

During execution, stack usage can be monitored via **View → Stack**.

For accurate measurement:
- Keep only the target function and required variables, and comment out all other code.
- Set a breakpoint at the target function and run the program up to that point.
- Execute the function, then compute the net stack usage as:

Net stack usage = (observed stack usage) - (size of local variables)


---

### 3. Code Size Measurement

Code size is measured based on the `*.map` file generated after the build process.




## Example
1. Create a workspace and project
In IAR, create a new Workspace and Project.

2. Manually add the source code
Add all source files to the project manually, including main.c.

3. Configure the board and optimization options

- Board setting
Go to Project Options → General Options → Target and select MSP430F67791.

- Optimization setting
Go to Project Options → C/C++ Compiler → Optimizations and set the optimization level to High (speed).

4. Run the program

Set breakpoints at the functions you want to measure in main.c. After that, click Download and Debug (the green button at the top) to start the execution.

5. Check the register view

Open the Register window by selecting View → Registers. As the program executes each function, you can monitor the changes in CYCLECOUNTER or CCSTEP in that window.





# Performance Comparison (Ref (Pure C) vs opt (This Work))

**Platform:** 16-bit MSP430 (MSP430F67791)
**Compiler Option:** High Speed Optimization
**Note:** 1 k = 1,000 cycles

## NTT / PWM / Keccak Performance 

| Category | Variant | Implementation | NTT | NTT⁻¹ | PWM | Keccak-f1600 |
|----------|--------|---------------|-----|-------|-----|---------------|
| NTT | 16-bit | C (Ref) | 102,505 | 175,840 | 51,939 | - |
| NTT | 16-bit | This Work (Asm) | 43,732 | 50,378 | 16,765 | - |
| NTT | 16-bit (q=257) | This Work (Asm) | 22,545 | 45,982 | 13,429 | - |
| NTT | 32-bit | C (Ref) | 158,038 | 206,692 | 32,546 | - |
| NTT | 32-bit | This Work (Asm) | 82,635 | 105,409 | 20,826 | - |
| Keccak | - | C (Ref) | - | - | - | 86,599 |
| Keccak | - | This Work (Asm) | - | - | - | 55,316 |

---

## Kyber Performance (C Reference)
| Level | Algorithm | Cycle (k cc) | Stack (B) |
|------|-----------|-------------|----------|
| 512 | KeyGen | 3,244 k | 6,146 |
| 512 | Encaps | 4,288 k | 8,804 |
| 512 | Decaps | 4,170 k | 9,576 |
| 768 | KeyGen | 5,480 k | 10,176 |
| 768 | Encaps | 7,204 k | 13,344 |
| 768 | Decaps | 7,070 k | 14,436 |
| 1024 | KeyGen | 8,620 k | 15,296 |
| 1024 | Encaps | 10,760 k | 18,976 |
| 1024 | Decaps | 10,559 k | 20,548 |

## Kyber Performance (This Work)
| Level | Algorithm | Cycle (k cc) | Stack (B) |
|------|-----------|-------------|----------|
| 512 | KeyGen | 2,221 k | 2,740 |
| 512 | Encaps | 2,946 k | 2,816 |
| 512 | Decaps | 2,852 k | 2,824 |
| 768 | KeyGen | 3,622 k | 3,190 |
| 768 | Encaps | 4,503 k | 3,266 |
| 768 | Decaps | 4,357 k | 3,274 |
| 1024 | KeyGen | 5,710 k | 3,704 |
| 1024 | Encaps | 6,820 k | 3,780 |
| 1024 | Decaps | 6,640 k | 3,794 |

---

## Dilithium Performance (C Reference)
| Level | Algorithm | Cycle (k cc) | Stack (B) |
|------|-----------|-------------|----------|
| 2 | KeyGen | 13,505 k | 13,236 |
| 2 | Sign | 105,419 k | 17,148 |
| 2 | Verify | 13,869 k | 16,622 |
| 3 | KeyGen | 24,638 k | 17,397 |
| 3 | Sign | 203,764 k | 21,540 |
| 3 | Verify | 24,480 k | 19,158 |
| 5 | KeyGen | 40,631 k | 21,005 |
| 5 | Sign | 271,094 k | 25,810 |
| 5 | Verify | 41,012 k | 23,458 |

## Dilithium Performance (This Work)
| Level | Algorithm | Cycle (k cc) | Stack (B) |
|------|-----------|-------------|----------|
| 2 | KeyGen | 9,142 k | 13,236 |
| 2 | Sign | 63,892 k | 18,172 |
| 2 | Verify | 9,251 k | 16,622 |
| 3 | KeyGen | 17,053 k | 17,397 |
| 3 | Sign | 129,404 k | 22,564 |
| 3 | Verify | 16,758 k | 19,158 |
| 5 | KeyGen | 27,399 k | 21,005 |
| 5 | Sign | 167,436 k | 26,834 |
| 5 | Verify | 27,345 k | 23,458 |

---


