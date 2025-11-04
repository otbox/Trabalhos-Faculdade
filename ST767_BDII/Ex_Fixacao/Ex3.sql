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
    valor DECIMAL(12,2) NOT NULL,
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
GO  -- Added batch separator


USE ViewDB;
GO

-- Inserting sample products
INSERT INTO Produto (codproduto, nome, preco, qtdestoque) VALUES (1, 'Product A', 10.50, 100);
INSERT INTO Produto (codproduto, nome, preco, qtdestoque) VALUES (2, 'Product B', 15.75, 200);
INSERT INTO Produto (codproduto, nome, preco, qtdestoque) VALUES (3, 'Product C', 8.25, 50);
GO

-- Inserting sample invoices (NotaFiscal)
INSERT INTO NotaFiscal (numnota, valortotal) VALUES (1001, 105.00);
INSERT INTO NotaFiscal (numnota, valortotal) VALUES (1002, 157.50);
GO

-- Inserting sample items for each invoice (itemnotafiscal)
INSERT INTO itemnotafiscal (numnota, codproduto, quantidade) VALUES (1001, 1, 5);   -- 5 units of Product A
INSERT INTO itemnotafiscal (numnota, codproduto, quantidade) VALUES (1001, 2, 3);   -- 3 units of Product B
INSERT INTO itemnotafiscal (numnota, codproduto, quantidade) VALUES (1002, 1, 2);   -- 2 units of Product A
INSERT INTO itemnotafiscal (numnota, codproduto, quantidade) VALUES (1002, 3, 10);  -- 10 units of Product C
GO

-- Inserting sample invoices details (Fatura)
INSERT INTO Fatura (numfatura, dtvencimento, dtpagamento, valor, numnota) 
VALUES (2001, '2025-11-01', '2025-11-05', 105.00, 1001);
INSERT INTO Fatura (numfatura, dtvencimento, dtpagamento, valor, numnota) 
VALUES (2002, '2025-11-02', NULL, 157.50, 1002);
GO

-- a)
CREATE VIEW prodnaoVendido AS
SELECT Produto.codproduto, nome, qtdestoque from Produto
Left JOIN itemnotafiscal on itemnotafiscal.codproduto = Produto.codproduto
WHERE itemnotafiscal.codproduto IS NULL;

select * from prodnaoVendido;  -- Querying the view as a table
-- b)
CREATE VIEW qntfoiVendido AS 
SELECT itemnotafiscal.codproduto, SUM(itemnotafiscal.quantidade) as total_vendido from itemnotafiscal
INNER JOIN Produto on Produto.codproduto = itemnotafiscal.codproduto
GROUP BY itemnotafiscal.codproduto;

CREATE VIEW qntfoiVendido AS 
SELECT 
    Produto.codproduto, 
    SUM(itemnotafiscal.quantidade) AS total_vendido
FROM itemnotafiscal
INNER JOIN Produto 
    ON Produto.codproduto = itemnotafiscal.codproduto
GROUP BY Produto.codproduto;

-- c) 
CREATE VIEW nfview as 
SELECT NotaFiscal.numnota, (itemnotafiscal.quantidade 
* Produto.preco) as precoVendido, nome, preco from NotaFiscal
JOIN itemnotafiscal on itemnotafiscal.numnota = NotaFiscal.numnota
INNER JOIN Produto on Produto.codproduto = itemnotafiscal.codproduto

-- d)
CREATE VIEW nfView2 as 
SELECT NotaFiscal.numnota, valortotal, dtvencimento, Fatura.valor FROM NotaFiscal
JOIN Fatura on Fatura.numnota = NotaFiscal.numnota
WHERE Fatura.dtpagamento is NULL


-- e)
Create view nfView3 as
SELECT nf.numnota, nf.valortotal FROM NotaFiscal nf 
WHERE not exists (
    SELECT 1 from Fatura f 
    where f.numnota = nf.numnota 
        and f.dtpagamento is NULL 
)

USE ViewDB;
GO