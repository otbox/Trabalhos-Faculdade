package model;

import model.RegraDeCalculo.RegraDeCalculoA;

public enum CategoriaCarro {
    A_HATCH_COMPACTO(new RegraDeCalculoA()),
    B_SEDAN_INTERMEDIARIO(new RegraDeCalculoB()),
    C_SUV_COMPACTO(new RegraDeCalculoC()),
    D_SEDAN_EXECUTIV(new RegraDeCalculoD()),
    E_SUV_EXECUTIVO(new RegraDeCalculoE());

    private final RegraDeCalculo regra;

    CategoriaCarro(RegraDeCalculo regra) {
        this.regra = regra;
    }
}
