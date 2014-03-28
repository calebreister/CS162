import json
f = json.load(open('StroidsConfig-DEFAULT.json'))
f['LASER']['EDGE_DEATH']
json.dumps(f,sort_keys=True,indent=4,separators=(',',': '))
f['SHIP']['COLOR']
f['SHIP']['COLOR'][0]
f['SHIP']['COLOR'][1]
f['SHIP']['COLOR'][2]
f['SHIP']['COLOR'][2] = 255
f['SHIP']['COLOR'][2]
json.dump(f,open('StroidsConfig-DEFAULT.json','w'),sort_keys=True,indent=4,separators=(',',': '))
import readline
readline.write_history_file('JSONPy.txt')
