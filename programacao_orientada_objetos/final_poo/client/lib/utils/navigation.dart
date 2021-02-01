import 'package:flutter/material.dart';

push({@required BuildContext context, @required screen}) {
  return Navigator.push(
    context,
    MaterialPageRoute(builder: (context) => screen),
  );
}
