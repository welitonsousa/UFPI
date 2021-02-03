import 'package:client/bloc/homeBloc.dart';
import 'package:client/data/notationType.dart';
import 'package:client/pages/details.dart';
import 'package:client/utils/navigation.dart';
import 'package:flutter/material.dart';

class Home extends StatefulWidget {
  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Anotações')),
      body: _body(),
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.add),
        onPressed: () async {
          await push(
              context: context,
              screen: Details(
                  editable: true, controller: homeController, register: true));
          homeController.getNotation();
        },
      ),
    );
  }

  HomeBloc homeController = HomeBloc();
  Widget _body() {
    return StreamBuilder<dynamic>(
      stream: homeController.stream,
      builder: (BuildContext context, snapshot) {
        List<Notation> listNotations = snapshot.data;
        if (snapshot.hasError) return Center(child: Text('Error'));
        if (!snapshot.hasData)
          return Center(child: CircularProgressIndicator());
        if (snapshot.data.length == 0)
          return Center(child: Text('Nenhuma nota salva'));
        return ListView.builder(
          itemCount: homeController.getItemCount(),
          itemBuilder: (BuildContext context, int index) {
            return ListTile(
              title: Text(listNotations[index].title),
              onTap: () async {
                await push(
                  context: context,
                  screen: Details(
                    editable: false,
                    register: false,
                    controller: homeController,
                    notation: listNotations[index],
                  ),
                
                );
                homeController.getNotation();
              },
            );
          },
        );
      },
    );
  }
}
