import 'package:dio/dio.dart';

import 'package:client/bloc/genericBloc.dart';
import 'package:client/data/notationType.dart';
import 'package:flutter/material.dart';

class HomeBloc extends GenerecBloc {
  List<Notation> notations = [];
  String _url = "http://10.0.2.2:5001/api/notation";

  Future<bool> getNotation() async {
    try {
      var res = await Dio().get(_url);
      List resMap = res.data['data'];
      List<Notation> listMap = resMap.map((e) => Notation.fromJson(e)).toList();

      notations = listMap;
      controller.add(notations);
      return true;
    } catch (e) {
      return false;
    }
  }

  Future<bool> postNotation(
      {@required String title, @required String notation}) async {
    try {
      var res = await Dio().post(_url, data: {'title': title, 'notation': notation});
      notations.add(Notation.fromJson(res.data));
      controller.add(notations);
      print(res.data);
      return true;
    } catch (e) {
      print('asdasd');
      return false;
    }
  }

  Future<bool> putNotation({@required Notation notation}) async {
    try {
      await Dio().put(_url, data: {
        'id': notation.id,
        'title': notation.title,
        'notation': notation.notation
      });
      notations.forEach((element) { 
        if (element.id == notation.id){
          element = notation;
        }
      });
      controller.add(notations);
      return true;
    } catch (e) {
      return false;
    }
  }

  Future<bool> deleteNotation({@required String id}) async {
    try{
      await Dio().delete(_url, data: {'id': id});
      return true;
    }catch(e){
      return false;
    }
  }

  int getItemCount() {
    return notations.length;
  }

  HomeBloc() {
    getNotation();
  }
}
