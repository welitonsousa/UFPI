use mydb;

insert into Clientes(nome, telefone, cpf) values ('darice', '89 988187281', '081.328.323-15');
select * from Clientes;

insert into Endereco(rua, bairro, cidade, estado, Clientes_id) values ('rua tal', 'bairro tal', 'cidade tal', 'estado tal2', 3);
insert into Endereco(rua, bairro, cidade, estado, Clientes_id) values ('rua vai ser deletada', 'bairro tal', 'cidade tal', 'estado tal2', 1);
select * from Endereco;

update Endereco set rua = 'rua no ceu tem pão' where Endereco.id = 2;
delete from Endereco where id = 2;
select * from Endereco;

insert into Produtos(nome_produto, preco, tipo, descricao) values ('Coca Cola', 5.99, 'Litrao', '3L');
insert into Produtos(nome_produto, preco, tipo) values ('mascara', 4.99, 'tecido');
select * from Produtos;

insert into Pedidos(quantidade, Produtos_id, Clientes_id) values (2,1,2);
delete from Pedidos where id = 4;
select * from Pedidos;

SELECT * FROM Clientes INNER JOIN Endereco ON Clientes.id = Endereco.Clientes_id;
select nome, quantidade  from Pedidos INNER JOIN Clientes ON Clientes.id = Pedidos.Clientes_id;