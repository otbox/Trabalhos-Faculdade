-- use master
-- go
-- drop database Ex4DB
Create Database Ex4DB 
go
use Ex4DB
go
Create table Pessoa (
    codigo int PRIMARY KEY,
    nome varchar(60),
    endereco varchar(80),
    telefone varchar(20)
); 
GO
CREATE table Cliente (
    codigo int PRIMARY KEY,
    rg varchar (20) UNIQUE,
    dtnasc date
    FOREIGN KEY (codigo) REFERENCES Pessoa(codigo)
);
CREATE INDEX idx_cliente_pessoa on Cliente(codigo)
GO
Create table Atendente(
    codigo int PRIMARY KEY,
    salario DECIMAL(10,2),
    comissao DECIMAL(10,2),
    FOREIGN KEY (codigo) REFERENCES Pessoa(codigo)
);
GO
CREATE INDEX idx_cliente_atendente on Atendente(codigo)
GO
Create table Venda(
    codigoCliente int,
    codigoAtendente int,
    codigo int PRIMARY KEY,
    data DATE,
    FOREIGN KEY (codigoCliente) REFERENCES Cliente(codigo),
    FOREIGN KEY (codigoAtendente) REFERENCES Atendente(codigo)
);
GO
CREATE INDEX idx_venda_cliente on Venda(codigoCliente)
CREATE INDEX idx_venda_atendente on Venda(codigoAtendente)
GO
create table Livro(
    codigo int PRIMARY KEY,
    titulo varchar(80),
    autor varchar(50),
    preco DECIMAL(10,2),
    qnt_estoque int,
)
GO
create table LivroVenda(
    codigoLivro int,
    codigoVenda int,
    qnt int,
    PRIMARY KEY(codigoVenda, codigoLivro),
    FOREIGN KEY (codigoLivro) REFERENCES Livro(codigo),
    FOREIGN KEY (codigoVenda) REFERENCES Venda(codigo),
);

-- 2
-- a 
BEGIN TRANSACTION;

BEGIN TRY
    INSERT INTO Pessoa VALUES (2, 'vander', 'endereco', '11233321');
    INSERT INTO Cliente VALUES (2, '1234', '2025-02-19');
    COMMIT TRANSACTION;
END TRY
BEGIN CATCH
    ROLLBACK TRANSACTION;
END CATCH;


-- b 
BEGIN TRANSACTION;
BEGIN TRY
    INSERT INTO Pessoa VALUES (1, 'Geraldo', 'endereco', '11233321');
    INSERT INTO Atendente VALUES (1, 12345, 10);
    COMMIT TRANSACTION;
END TRY
BEGIN CATCH
    ROLLBACK TRANSACTION;
END CATCH;


INSERT INTO Livro VALUES (1, 'Levítico', 'Deus', 15, 4);
-- C)
BEGIN TRANSACTION;
BEGIN TRY
    INSERT INTO Venda VALUES (2, 1, 1, '2025-09-10');
    INSERT INTO LivroVenda VALUES (1, 1, 1);
    UPDATE Livro SET qnt_estoque = qnt_estoque - 1 where codigo = 1;
    COMMIT TRANSACTION;
END TRY
BEGIN CATCH
    ROLLBACK TRANSACTION;
END CATCH;

SELECT * from Cliente
SELECT * from Atendente
SELECT * from Livro
SELECT * from Venda
SELECT * from LivroVenda