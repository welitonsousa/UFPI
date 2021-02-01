from interface_CRUD import InterfaceCRUD
from file_data import DataNotation
import uuid 

class ServiceData (InterfaceCRUD, DataNotation):
    def post(self, title: str, notation: str):
        try:
            dic = {'id': str(uuid.uuid1().hex), 'title': title, 'notation': notation}
            self._list_notation.append(dic)
            return dic
        except: 
            return False

    def get(self):
        try:
            return self._list_notation
        except:
            return False
    
    def put(self, id: str, title: str, notation: str):
        try:
            for index in range(0, len(self._list_notation)):
                if self._list_notation[index]['id'] == id:
                    dic = {'id': self._list_notation[index]['id'], 'title': title, 'notation': notation}
                    self._list_notation[index] = dic
                    return True
            return False
        except:
            return False

    def delete(self, id: str):
        try:
            for notation in self._list_notation:
                if notation['id'] == id:
                    self._list_notation.remove(notation)
                    return True
            return False
        except:
            return False
