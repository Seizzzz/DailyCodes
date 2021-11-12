import socket
import json
from query import Query

query = Query('./index')


def search(request):
    res = query.standard_search(request)
    context = {
        'query': request,
        'resCount': len(res),
        'results': res
    }
    return context


def extract(request):
    if len(query.standard_search(request)) > 0:
        results = query.regex_extract(request)
        adjs, poss, ages, times = list(), list(), list(), list()
        wdN = 0
        for r in results:
            for ir in r['adjs']:
                adjs.append(ir)
            for ir in r['poss']:
                poss.append(ir[0])
            for ir in r['ages']:
                ages.append(ir)
            for ir in r['times']:
                times.append(ir)
            wdN += r['wdN']
        if len(adjs) > 10:
            adjs = adjs[:10]
        if len(poss) > 10:
            poss = poss[:10]
        if len(ages) > 10:
            ages = ages[:10]
        if len(times) > 10:
            times = times[:10]
        context = {
            'query': request,
            'adjs': adjs,
            'poss': poss,
            'ages': ages,
            'times': times,
            'wdN': wdN
        }
        return context


addr = ('127.0.0.1', 62101)
srv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
srv.bind(addr)

while True:
    data, clt = srv.recvfrom(4096)
    text = data.decode('utf-8')
    print(text)

    msg = json.loads(text)
    if msg["type"] == "search":
        ret = search(msg["query"])
        ret["type"] = "search"
        print(ret)
    else:
        ret = extract(msg["query"])
        ret["type"] = "extract"
        print(ret)

    srv.sendto(bytes(json.dumps(ret, ensure_ascii=False), encoding='utf-8'), clt)

# print(search('说'))
# print(extract('苏铭'))
