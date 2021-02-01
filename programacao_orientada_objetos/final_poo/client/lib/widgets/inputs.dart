import 'package:flutter/material.dart';

class Inputs {
  static Widget textFormField({
    bool enable,
    TextEditingController controller,
    String label = '',
    heigth = 2,
  }) {
    return TextFormField(
      enabled: enable,
      controller: controller,
      keyboardType: TextInputType.multiline,
      decoration: InputDecoration(
          labelText: label,
          border:
              OutlineInputBorder(borderSide: BorderSide(color: Colors.black))),
      maxLines: 200000000,
      minLines: heigth,
      // controller: cpfcontroller,
    );
  }
}
