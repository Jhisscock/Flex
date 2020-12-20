#ifndef CODENUM_H
#define CODENUM_H

#define ADI 0
#define SBI 1
#define MLI 2
#define DVI 3
#define NGI 4
#define ADF 5
#define SBF 6
#define MLF 7
#define DVF 8
#define NGF 9
#define EQI 10
#define NEI 11
#define LTI 12
#define LEI 13
#define GTI 14
#define GEI 15
#define EQF 16
#define NEF 17
#define LTF 18
#define LEF 19
#define GTF 20
#define GEF 21
#define FTI 22
#define ITF 23
#define PTI 24
#define PTF 25
#define PTC 26
#define PTL 27
#define INI 28
#define INF 29
#define LLI 30
#define LLF 31
#define ISP 32
#define DSP 33
#define STO 34
#define STM 35
#define LOD 36
#define LAA 37
#define LRA 38
#define JMP 39
#define JPF 40
#define PAR 41
#define CAL 42
#define RET 43
#define NOP 44
#define HLT 45

struct codepair{
    int instruction;
    int imod;
    float fmod;
};

struct jumppoint{
    int jp;
    struct jumppoint* next;
};


#endif