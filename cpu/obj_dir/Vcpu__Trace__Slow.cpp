// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


//======================

void Vcpu::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vcpu::traceInit, &Vcpu::traceFull, &Vcpu::traceChg, this);
}
void Vcpu::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vcpu* t = (Vcpu*)userthis;
    Vcpu__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vcpu::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcpu* t = (Vcpu*)userthis;
    Vcpu__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vcpu::traceInitThis(Vcpu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vcpu::traceFullThis(Vcpu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcpu::traceInitThis__1(Vcpu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBus(c+25,"instruction", false,-1, 31,0);
        vcdp->declBus(c+33,"result", false,-1, 31,0);
        vcdp->declBus(c+25,"cpu instruction", false,-1, 31,0);
        vcdp->declBus(c+33,"cpu result", false,-1, 31,0);
        vcdp->declBus(c+41,"cpu opcode", false,-1, 6,0);
        vcdp->declBus(c+1,"cpu rd", false,-1, 4,0);
        vcdp->declBus(c+9,"cpu rs1", false,-1, 4,0);
        vcdp->declBus(c+17,"cpu imm", false,-1, 11,0);
        vcdp->declBus(c+25,"cpu ID instruction", false,-1, 31,0);
        vcdp->declBus(c+41,"cpu ID opcode", false,-1, 6,0);
        vcdp->declBus(c+1,"cpu ID rd", false,-1, 4,0);
        vcdp->declBus(c+9,"cpu ID rs1", false,-1, 4,0);
        vcdp->declBus(c+17,"cpu ID imm", false,-1, 11,0);
        vcdp->declBus(c+41,"cpu EU opcode", false,-1, 6,0);
        vcdp->declBus(c+1,"cpu EU rd", false,-1, 4,0);
        vcdp->declBus(c+9,"cpu EU rs1", false,-1, 4,0);
        vcdp->declBus(c+17,"cpu EU imm", false,-1, 11,0);
        vcdp->declBus(c+33,"cpu EU result", false,-1, 31,0);
        vcdp->declBus(c+41,"cpu CL opcode", false,-1, 6,0);
        vcdp->declBus(c+1,"cpu CL rd", false,-1, 4,0);
        vcdp->declBus(c+9,"cpu CL rs1", false,-1, 4,0);
        vcdp->declBus(c+17,"cpu CL imm", false,-1, 11,0);
    }
}

void Vcpu::traceFullThis__1(Vcpu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->cpu__DOT__rd),5);
        vcdp->fullBus(c+9,(vlTOPp->cpu__DOT__rs1),5);
        vcdp->fullBus(c+17,(vlTOPp->cpu__DOT__imm),12);
        vcdp->fullBus(c+25,(vlTOPp->instruction),32);
        vcdp->fullBus(c+33,(vlTOPp->result),32);
        vcdp->fullBus(c+41,((0x7fU & vlTOPp->instruction)),7);
    }
}
