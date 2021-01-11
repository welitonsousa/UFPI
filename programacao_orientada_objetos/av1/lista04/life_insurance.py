
class LifeInsurance:

    def __init__(self, total_value: float):
        self._total_value = total_value
        self._monthly_value = total_value / 12

    @property
    def get_data_life(self):
        return {'total_value': self._total_value, 'monthly_value': self._monthly_value}
