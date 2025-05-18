package model;

public abstract class RegraDeCalculo {
    protected double valorKm;
    protected double qntDias;
    protected double kmPercorridos;

    public void setValorKm(double valorKm) {
        this.valorKm = valorKm;
    }

    public double getValorKm() {
        return valorKm;
    }

    public double getQntDias() {
        return qntDias;
    }

    public void setQntDias(double qntDias) {
        this.qntDias = qntDias;
    }

    public double getKmPercorridos() {
        return kmPercorridos;
    }

    public void setKmPercorridos(double kmPercorridos) {
        this.kmPercorridos = kmPercorridos;
    }

    public double calcula() {
        return valorKm * qntDias * kmPercorridos;
    } 
    
    public class RegraDeCalculoA extends RegraDeCalculo {

        public RegraDeCalculoA() {
        }
    }
    public class RegraDeCalculoB extends RegraDeCalculo {

        public RegraDeCalculoB() {
        }
    }
    public class RegraDeCalculoC extends RegraDeCalculo {

        public RegraDeCalculoC() {
        }
    }
    public class RegraDeCalculoD extends RegraDeCalculo {

        public RegraDeCalculoD() {
        }
    }
    public class RegraDeCalculoE extends RegraDeCalculo {

        public RegraDeCalculoE() {
        }
    }


}