use master
GO
DROP DATABASE ViewDB
GO
create Database ViewDB
GO
USE ViewDB
GO
create table NotaFiscal (
    numnota int NOT NULL,
    valortotal DECIMAL(12,2) NOT NULL,
    PRIMARY KEY (numnota)
);
go
create TABLE Produto (
    codproduto int NOT NULL,
    nome varchar(80) NOT NULL,
    preco DECIMAL(10,2) NOT NULL,
    qtdestoque int DEFAULT 0,
    PRIMARY KEY (codproduto)
);
GO
create table Fatura(
    numfatura int NOT NULL,
    dtvencimento DATE NOT NULL,
    dtpagamento DATE,
    valor DECIMAL(12,2) NOT NULL
    numnota INT NOT NULL,
    FOREIGN KEY (numnota) REFERENCES NotaFiscal(numnota)
);
GO 
CREATE INDEX idx_fatura_numnota
    ON Fatura(numnota);
GO
create table itemnotafiscal(
    numnota int,
    codproduto int,
    quantidade int,
    FOREIGN KEY (numnota) REFERENCES NotaFiscal (numnota),
    FOREIGN KEY (codproduto) REFERENCES Produto (codproduto)
);
GO
CREATE INDEX idx_item_nota ON NotaFiscal(numnota);
GO
CREATE INDEX idx_item_produto ON Produto(codproduto);
GO
-- a)
CREATE VIEW prodnaoVendido AS
SELECT Produto.codproduto, nome, qtdestoque from Produto
Left JOIN itemnotafiscal on itemnotafiscal.codproduto = Produto.codproduto
WHERE itemnotafiscal.codproduto = NULL;
-- b)
