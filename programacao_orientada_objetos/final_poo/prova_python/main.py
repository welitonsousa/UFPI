from flask import Flask, json, Response
from flask.globals import request
from service_data import ServiceData

app = Flask(__name__)

@app.route('/api/notation', methods=['GET'])
def notation_get():
    try:
        res = ServiceData().get()
        if res == False:
            fail()
        return Response(response=json.dumps({'data': res}), status=200, mimetype='application/json')
    except:
        return fail()

@app.route('/api/notation', methods=['POST'])
def notation_post():
    try:
        data = request.json
        title = data['title']
        notation = data['notation']
        res = ServiceData().post(title, notation)
        if res == False:
            return fail()
        return Response(response=json.dumps(res), status=200, mimetype='application/json')
    except:
        print('except')
        return Response(status=400, mimetype='application/json')

@app.route('/api/notation', methods=['PUT'])
def notation_put():
    try:
        data = request.json
        id = data['id']
        title = data['title']
        notation = data['notation']
        res = ServiceData().put(id, title, notation)
        if res == False:
            return fail()
        return success()
    except:
        return fail()

@app.route('/api/notation', methods=['DELETE'])
def notation_delete():
    try:
        data = request.json
        id = data['id']
        res = ServiceData().delete(id)
        print(res)
        if res == False:
            return fail()
        return success()
    except:
        return fail()

def fail():
    return Response(status=400, mimetype='application/json')

def success():
    return Response(response=json.dumps({'message': 'success'}), status=200, mimetype='application/json')

if __name__ == '__main__':
    app.run(debug=True, port=5001, host='127.0.0.1')

