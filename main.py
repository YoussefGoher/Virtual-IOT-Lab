from flask import *
import time
import os

app = Flask(__name__)
app.config["SECRET_KEY"] = os.environ.get("SECRET_KEY", "your_fallback_secret_key")
file_positions = {}
status=0

@app.route('/')
def index():
	return send_from_directory("website_htmls","index.html")

@app.route('/LEDON.html')
def LEDON():
	global status
	with open("files/status.txt","w") as statusfile:
		statusfile.write("1")
	status=1
	return send_from_directory("website_htmls","LEDON.html")

@app.route('/LEDOFF.html')
def LEDOFF():
	global status
	with open("files/status.txt","w") as statusfile:
		statusfile.write("0")
	status=0
	return send_from_directory("website_htmls","LEDOFF.html")

@app.route('/status')
def get_status():
	return f"{status}"

@app.route('/files/<path:file_path>')
def get_file(file_path):
    full_path = f'files/{file_path}'
    try:
        return send_file(full_path)
    except FileNotFoundError:
        return "File not found", 404


@app.route('/apps/<id>/<path:file_path>')
def get_app(id, file_path):
    full_path = f'apps/{file_path}'

    # Use the combination of ID and file_path as a unique identifier
    unique_id = f"{id}_{file_path}"

    # Check if there is already a position tracked for this file for this ID
    if unique_id not in file_positions:
        file_positions[unique_id] = 0

    try:
        with open(full_path, 'r') as file:
            lines = file.readlines()
            position = file_positions[unique_id]

            if position >= len(lines):
                file_positions[unique_id] = 0  # Reset
                return "End of file reached. Position reset.", 200
            #time.sleep(0.01)
            # Send the current line and update position
            current_line = lines[position].strip()
            file_positions[unique_id] = position + 1
            return current_line

    except FileNotFoundError:
        return "File not found", 404

if __name__ == "__main__":
	app.run(host='0.0.0.0')

