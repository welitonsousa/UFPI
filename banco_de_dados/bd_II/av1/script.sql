############################### deletando as tabelas ##############################

drop table if exists vendas;
drop table if exists telefone;
drop table if exists aparelho;
drop table if exists planos;
drop table if exists endereco;
drop table if exists cliente;
drop table if exists vendedor;


############################### criando as tabelas ##############################


create table if not exists cliente (
    id int primary key auto_increment unique,
	nome varchar(100) not null,
    cpf varchar(11) not null unique,
    idade int
);

create table if not exists endereco (
    id int primary key auto_increment unique,
    rua varchar(50) not null,
    numero int not null,
    bairro varchar(50) not null,
    cpf varchar(11) not null,
    foreign key (cpf) references cliente(cpf)
);

create table if not exists planos(
	id int primary key not null unique auto_increment,
	nome varchar(50) not null,
	preco double not null
);

create table if not exists aparelho (
    id int primary key auto_increment unique,
   	nome varchar(50) not null,
   	preco double not null,
	id_plano int not null,
   	foreign key (id_plano) references planos(id)
);

create table if not exists telefone (
    id int primary key auto_increment unique,
    telefone varchar(11) not null unique,
    id_aparelho int not null,
    foreign key (id_aparelho) references aparelho(id)
);

create table if not exists vendedor (
    id int primary key auto_increment unique,
   	nome varchar(50) not null,
   	cpf varchar(50) not null unique
);

create table if not exists vendas (
    id int primary key auto_increment unique,
    cpf_vendedor varchar(11) not null,
   	foreign key (cpf_vendedor) references vendedor(cpf),
   	cpf_cliente varchar(11) not null,
   	foreign key (cpf_cliente) references cliente(cpf),
   	id_aparelho int not null,
   	foreign key (id_aparelho) references aparelho(id),
   	create_at datetime not null default(now())
);


############################### populando as tabelas ##############################


insert into cliente (nome, cpf, idade) values ('weliton sousa', '07812882314', 22);
insert into cliente (nome, cpf, idade) values ('darice sousa', '123321', 22);
select * from cliente;

insert into endereco (rua, numero, bairro, cpf) values ('pedro claro', 3850, 'junco' ,'07812882314');
insert into endereco (rua, numero, bairro, cpf) values ('besouro', 195, 'bocaina' ,'07812882314');
insert into endereco (rua, numero, bairro, cpf) values ('besouro', 195, 'bocaina' ,'123321');
select * from endereco;

insert into planos (nome, preco) values ('sem plano', 0.0);
insert into planos (nome, preco) values ('internet', 20.0);
insert into planos (nome, preco) values ('ligacoes', 10.0);
select * from planos;

insert into aparelho (nome, preco, id_plano) values ('sansumg', 1000, 1);
select * from aparelho;

insert into telefone (telefone, id_aparelho) values ('89988187280', 1);
select * from telefone;

insert into vendedor (nome, cpf) values ('weliton sousa', '07812882314');
select * from vendedor;

insert into vendas (cpf_vendedor, cpf_cliente, id_aparelho) values ('07812882314', '123321', 1);
select * from vendas;


############################### pesquisas importantes ##############################


#retorna no maior preco dos planos
select max(preco) from planos;

# busca o cpf que tem mais enderecos
select cpf, count(cpf) as qtd
from endereco
group by cpf
order by qtd desc limit 1;

# junta a tabela cliente com a tabale endereco e pesquisa pelo cpf tal
select * from cliente inner join endereco on cliente.cpf = endereco.cpf where cliente.cpf = '123321';
