"""
Crie uma classe Televisao e uma classe ControleRemoto que pode controlar o volume e trocar os canais da
televisão. O controle de volume permite: aumentar ou diminuir a potência do volume de som em uma unidade
de cada vez; aumentar e diminuir o número do canal em uma unidade trocar para um canal indicado; consultar
o valor do volume de som e o canal selecionado. A classe controle remoto deve possuir um menu iterativo para
o usuário escolher as opções desejadas.
"""


class Television:
    _channel = 1
    _volume = 50

    @property
    def channel(self):
        return self.__class__._channel

    @channel.setter
    def channel(self, new_channel):
        self.__class__._channel = new_channel
        print('Novo canal:', new_channel)

    @property
    def volume(self):
        return self.__class__._volume

    @volume.setter
    def volume(self, new_volume):
        self.__class__._volume = new_volume
        print('Novo volume:', new_volume)


class Control:
    _current_channel = Television().channel
    _current_volume = Television().volume

    def up_channel(self):
        if self._current_channel < 100:
            self.__class__._current_channel += 1
            Television().channel = self.__class__._current_channel

    def down_channel(self):
        if self._current_channel > 1:
            self.__class__._current_channel -= 1
            Television().channel = self.__class__._current_channel

    def up_volume(self):
        if self._current_volume < 100:
            self.__class__._current_volume += 1
            Television().volume = self.__class__._current_volume

    def down_volume(self):
        if self._current_volume > 0:
            self.__class__._current_volume -= 1
            Television().volume = self.__class__._current_volume

    @property
    def channel(self):
        return self.__class__._current_volume

    @channel.setter
    def channel(self, new_channel):
        if (new_channel <= 100) and (new_channel > 0):
            self.__class__._current_channel = new_channel
            Television().channel = new_channel
        else:
            print('Canal invalido')


control = Control()

while True:
    print('1 - Almentar volume')
    print('2 - Diminuir volume')
    print('3 - Almentar canal')
    print('4 - Diminuir canal')
    print('5 - Escolher canal')
    print('0 - Sair')
    option = int(input('Opcao: '))
    if option == 0:
        break

    elif option == 1:
        control.up_volume()

    elif option == 2:
        control.down_volume()

    elif option == 3:
        control.up_channel()

    elif option == 4:
        control.down_channel()

    elif option == 5:
        control.channel = int(input('Novo canal: '))
