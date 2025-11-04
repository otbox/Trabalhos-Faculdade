USE Marcenaria

Create view VwQntProdutoVendido AS
SELECT Produto.codigo, COUNT(*) AS QntVendido, Item.nome as NomeProduto, preco, preco_custo FROM VendaProduto
INNER JOIN Produto on Produto.codigo = VendaProduto.cod_produto
INNER JOIN Item on Item.codigo = Produto.codigo 
GROUP BY Produto.codigo, Item.nome, Produto.preco, Item.preco_custo;

CREATE TRIGGER trigger_atualizar_valor_venda_projeto_ao_inserir on Projeto
AFTER INSERT
AS
BEGIN 
    SET NOCOUNT ON;
    UPDATE Venda SET valor_total = valor_total + i.valor
    FROM Venda
    INNER JOIN inserted i on Venda.codigo = i.codigo_venda;
END;

CREATE TRIGGER trigger_atualizar_valor_venda_projeto_ao_atualizar
ON Projeto
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;
    UPDATE v
    SET v.valor_total = v.valor_total - d.valor + i.valor
    FROM Venda v
    INNER JOIN deleted d ON v.codigo = d.codigo_venda
    INNER JOIN inserted i ON v.codigo = i.codigo_venda;
END;

CREATE TRIGGER trigger_adicionar_qnt_mp_por_op on MateriaOrdem
AFTER INSERT
AS 
BEGIN
    SET NOCOUNT ON;
    UPDATE it set it.qnt_estoque = it.qnt_estoque + i.quantidade
    FROM Item it
    INNER JOIN inserted i  on it.codigo = i.codigo_materia
    INNER JOIN Item it on 



UPDATE Projeto SET valor = 20000 where id = 7;

INSERT INTO Projeto (id, codigo_venda, descricao, data_criacao, valor)
VALUES (7, 2, 'Balcão sob medida em MDF branco fosco', GETDATE(), 850.00);
INSERT INTO Projeto (id, codigo_venda, descricao, data_criacao, valor)
VALUES (8, 2, 'Balcão sob medida em MDF branco fosco', GETDATE(), 850.00);

SELECT * from Venda

DROP PROCEDURE insere_materia_prima

CREATE PROCEDURE insere_materia_prima
    @codigo INT,
    @nome VARCHAR(100),
    @descricao VARCHAR(200),
    @qnt_estoque INT,
    @preco_custo DECIMAL(10,2),
    @tipo_material VARCHAR(50)
AS
BEGIN
    BEGIN TRANSACTION;

    INSERT INTO Item (codigo, nome, descricao, qnt_estoque, preco_custo)
    VALUES (@codigo, @nome, @descricao, @qnt_estoque, @preco_custo);

    IF @@ROWCOUNT > 0
    BEGIN
        INSERT INTO MateriaPrima (codigo, tipo_material)
        VALUES (@codigo, @tipo_material);

        IF @@ROWCOUNT > 0
            COMMIT TRANSACTION;
        ELSE
            ROLLBACK TRANSACTION;
    END
    ELSE
        ROLLBACK TRANSACTION;
END;
GO

EXEC insere_materia_prima
    @codigo = 9,
    @nome = 'Tábua MDF 25mm',
    @descricao = 'Placa de MDF 2x1m',
    @qnt_estoque = 30,
    @preco_custo = 150.00,
    @tipo_material = 'Madeira MDF';

select * from MateriaPrima


CREATE PROCEDURE insere_materia_prima
    @nome VARCHAR(100),
    @descricao VARCHAR(200),
    @qnt_estoque INT,
    @preco_custo DECIMAL(10,2),
    @tipo_material VARCHAR(50)
AS
BEGIN
    BEGIN TRANSACTION;

    -- Inserir o item
    INSERT INTO Item (nome, descricao, qnt_estoque, preco_custo)
    VALUES (@nome, @descricao, @qnt_estoque, @preco_custo);

    IF @@ROWCOUNT > 0
    BEGIN
        DECLARE @novo_codigo_item INT;
        SET @novo_codigo_item = SCOPE_IDENTITY();

        -- Inserir na tabela MateriaPrima
        INSERT INTO MateriaPrima (codigo, tipo_material)
        VALUES (@novo_codigo_item, @tipo_material);

        IF @@ROWCOUNT > 0
            COMMIT TRANSACTION;
        ELSE
            ROLLBACK TRANSACTION;
    END
    ELSE
        ROLLBACK TRANSACTION;
END;
GO

EXEC insere_materia_prima
    @nome = 'Tábua MDF 25mm',
    @descricao = 'Placa de MDF 2x1m',
    @qnt_estoque = 30,
    @preco_custo = 150.00,
    @tipo_material = 'Madeira MDF';


create trigger inclusaoitemnota on itemnotafiscal for insert
as 
    update produto 
    set qtdestoque = qtdestoque - (select quantidade from inserted)
    where codproduto = (select dcodproduto from inserted)
    if @@rowcount > 0 
    BEGIN
        update notafiscal
        set valortotal = valortotal + (select i.quantidade * p.preco from produto p inner join inserted i on p.codproduto = i.codproduto)
        where numnota = (select numnota from inserted)
        if @@rowcount= 0 
            rollback transaction 
        end 
        else 
            rollback transaction