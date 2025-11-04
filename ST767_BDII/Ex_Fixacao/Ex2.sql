    ,
    
    
create DATABASE BancoDados
go
use BancoDados
go
-- 1-)

create table Veiculo (
    placa varchar(7) NOT NULL,
    marca varchar(50) NOT NULL,
    cor varchar(30) NOT NULL,
    PRIMARY KEY (placa)   
);
GO
create table Cliente (
    codigo INT NOT NULL,
    rg varchar(20) UNIQUE NOT NULL,
    nome varchar(50) NOT NULL,
    endereco varchar(100) NOT NULL,  
    PRIMARY KEY (codigo)
);
GO
create table Motorista (
    codigo INT NOT NULL,
    nome varchar(50) NOT NULL,
    nro_carteira int UNIQUE NOT NULL,
    hora_entrada TIME NOT NULL, 
    hora_saida TIME, 
    PRIMARY KEY (codigo)
);
GO
create table Ocorrencia (
    codigo INT NOT NULL,
    placa VARCHAR(7) NOT NULL,
    cod_cliente INT NOT NULL,
    cod_motorista int NOT NULL,
    end_busca varchar(100),
    end_entrega varchar(100) NOT NULL,
    data_ocorrencia DATETIME NOT NULL,
    distancia DECIMAL(10,3),
    preco DECIMAL(10,2) NOT NULL,
    pago BIT NOT NULL,
    PRIMARY KEY (codigo),
    FOREIGN KEY (cod_cliente) REFERENCES Cliente (codigo),
    FOREIGN KEY (cod_motorista) REFERENCES Motorista (codigo),
    FOREIGN KEY (placa) REFERENCES Veiculo (placa)
);
GO
CREATE INDEX idx_ocorrencia_cliente ON Ocorrencia(cod_cliente);
CREATE INDEX idx_ocorrencia_veiculo ON Ocorrencia(placa);
CREATE INDEX idx_ocorrencia_motorista ON Ocorrencia(cod_motorista);

-- 2)
-- a)
INSERT INTO Motorista (codigo, nome, nro_carteira, hora_entrada, hora_saida)
VALUES (1, 'Carlos Silva', 123456, '08:00:00', '17:00:00');
-- b)
INSERT INTO Cliente (codigo, rg, nome, endereco)
VALUES (1, '123456789', 'João Pedro', 'Rua do Flamingo, 123');

-- c)
INSERT INTO Veiculo (placa, marca, cor)
VALUES ('ABC1234', 'Fusca', 'azul');

-- d)
INSERT INTO Ocorrencia (codigo, placa, cod_cliente, cod_motorista, end_busca, end_entrega, data_ocorrencia, distancia, preco, pago)
VALUES (1, 'ABC1234', 1, 1, 'Rua do Carvalho, 456', 'Avenida das Flores, 789', '2025-04-15 10:00:00', 12.345, 100.00, 1);

-- e) 
UPDATE Ocorrencia SET pago = 1 WHERE codigo = 10;

-- f)
UPDATE Motorista SET hora_saida = '18:00:00' WHERE codigo = 5; 

-- g>
DELETE FROM Ocorrencia WHERE pago = 1 AND data_ocorrencia BETWEEN '2025-4-1' and '2025-6-1';

-- h)
DELETE FROM Veiculo WHERE placa = 'AAA555';

-- i)
SELECT * FROM Motorista WHERE hora_entrada = '6:00:00' AND hora_saida = '13:00:00';

-- j)
SELECT COUNT(pago) AS qnt_pagas FROM Ocorrencia WHERE pago = 1;

-- k)
SELECT data_ocorrencia, AVG(preco) FROM Ocorrencia GROUP BY data_ocorrencia;

-- l) 
SELECT nome FROM Cliente JOIN Ocorrencia ON Cliente.codigo = Ocorrencia.cod_cliente WHERE pago = 0;

-- m)
SELECT placa, Motorista.nome, data_ocorrencia, distancia 
FROM Ocorrencia 
JOIN Motorista 
ON Ocorrencia.cod_motorista = Motorista.codigo
ORDER BY data_ocorrencia;

-- n)
SELECT Cliente.nome AS NomeCliente, Motorista.nome AS NomeMotorista, data_ocorrencia, preco  FROM Ocorrencia 
JOIN Cliente ON Ocorrencia.cod_cliente = Cliente.codigo
JOIN Motorista ON Ocorrencia.cod_motorista = Motorista.codigo
WHERE pago = 0 
ORDER BY data_ocorrencia, Cliente.nome