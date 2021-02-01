import abc

class InterfaceCRUD(abc.ABC):
    #todas as classes que estendem desta classe é obrigada a implemetar todos 
    #esse metodosm referenter a um sistema de crud interno nesta api rest 
    
    @abc.abstractmethod
    def get(self):
        pass

    @abc.abstractmethod
    def post(self):
        pass

    @abc.abstractmethod
    def put(self):
        pass

    @abc.abstractmethod
    def delete(self):
        pass