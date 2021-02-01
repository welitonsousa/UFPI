import 'dart:async';

class GenerecBloc<T>{
  StreamController<T> controller = StreamController<T>();
  Stream get stream => controller.stream;

  void add(T element){
    controller.add(element);
  }
}