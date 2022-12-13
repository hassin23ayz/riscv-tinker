// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


//======================

void Vcpu::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vcpu* t = (Vcpu*)userthis;
    Vcpu__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vcpu::traceChgThis(Vcpu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vcpu::traceChgThis__2(Vcpu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->cpu__DOT__rd),5);
        vcdp->chgBus(c+9,(vlTOPp->cpu__DOT__rs1),5);
        vcdp->chgBus(c+17,(vlTOPp->cpu__DOT__imm),12);
    }
}

void Vcpu::traceChgThis__3(Vcpu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+25,(vlTOPp->instruction),32);
        vcdp->chgBus(c+33,(vlTOPp->result),32);
        vcdp->chgBus(c+41,((0x7fU & vlTOPp->instruction)),7);
    }
}
