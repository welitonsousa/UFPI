import 'package:client/bloc/homeBloc.dart';
import 'package:client/data/notationType.dart';
import 'package:client/widgets/inputs.dart';
import 'package:flutter/material.dart';

bool _editable, _register = false;
HomeBloc _controller;

TextEditingController _titleController = TextEditingController(text: '');
TextEditingController _notationController = TextEditingController(text: '');
String _idController = '';
Notation _notation;

class Details extends StatefulWidget {
  Details(
      {@required editable,
      @required controller,
      @required bool register,
      Notation notation}) {
    _editable = editable;
    _controller = controller;
    _register = register;
    if (notation != null) {
      _titleController.text = notation.title;
      _notationController.text = notation.notation;
      _idController = notation.id;
      _notation = notation;
    }if(register){
      _titleController.clear();
      _notationController.clear();
    }
  }
  @override
  _DetailsState createState() => _DetailsState();
}

class _DetailsState extends State<Details> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Nota'),
        actions: _actions(),
      ),
      body: _body(),
    );
  }

  Widget _body() {
    return ListView(
      padding: EdgeInsets.all(10),
      children: [
        Container(height: 10),
        Inputs.textFormField(
            enable: _editable, label: 'Titulo', controller: _titleController),
        Container(height: 10),
        Inputs.textFormField(
            enable: _editable,
            label: 'Conteudo',
            controller: _notationController),
      ],
    );
  }

  List<Widget> _actions(){
    return _register
            ? [
                IconButton(
                  icon: Icon(Icons.save),
                  onPressed: () async {
                    if (_editable &&
                        _notationController.text.isNotEmpty &&
                        _titleController.text.isNotEmpty) {
                      bool res = await _controller.postNotation(
                          title: _titleController.text,
                          notation: _notationController.text);
                      _controller.getNotation();
                      setState(() {
                        if (res) {
                          Navigator.pop(context);
                        }
                      });
                    } else if (_editable) {
                      setState(() {
                        _editable = !_editable;
                      });
                    }
                  },
                )
              ]
            : [
                IconButton(
                  icon: Icon(Icons.delete),
                  onPressed: () async {
                    bool res = await _controller.deleteNotation(id: _idController);
                    if (res) {
                      Navigator.pop(context);
                    }
                  },
                ),
                IconButton(
                  icon: _editable ? Icon(Icons.save) : Icon(Icons.edit),
                  onPressed: () async {
                    if (_editable &&
                        _idController.isNotEmpty &&
                        _notationController.text.isNotEmpty &&
                        _titleController.text.isNotEmpty) {
                      _notation.id = _idController;
                      _notation.notation = _notationController.text;
                      _notation.title = _titleController.text;
                      bool res =
                          await _controller.putNotation(notation: _notation);
                      setState(() {
                        if (res) {
                          _editable = !_editable;
                        }
                      });
                    } else if (!_editable) {
                      setState(() {
                        _editable = !_editable;
                      });
                    }
                  },
                ),
              ];
  }
}
