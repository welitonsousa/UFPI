class Notation {
  String id;
  String notation;
  String title;

  Notation({this.id, this.notation, this.title});

  Notation.fromJson(Map<String, dynamic> json) {
    id = json['id'];
    notation = json['notation'];
    title = json['title'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['id'] = this.id;
    data['notation'] = this.notation;
    data['title'] = this.title;
    return data;
  }
}
