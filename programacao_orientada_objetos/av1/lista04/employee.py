from person import Person


class Employee(Person):
    def __init__(self, name: str, cpf: str, date_birth: str, salary: float):
        super().__init__(name, cpf, date_birth)
        self._salary = salary

    @property
    def get_data_employee(self):
        return {'person': self.get_data_person, 'data': {'salary': self._salary}}
