import tkinter as tk
from tkinter import messagebox
import threading
import os
import webbrowser
from server import app

class ServerThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.daemon = True

    def run(self):
        app.run(host='0.0.0.0', port=5000)

class FileTransferApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Wireless File Transfer")

        self.start_button = tk.Button(root, text="Start Server", command=self.start_server)
        self.start_button.pack(pady=10)

        self.stop_button = tk.Button(root, text="Stop Server", command=self.stop_server, state=tk.DISABLED)
        self.stop_button.pack(pady=10)

        self.status_label = tk.Label(root, text="Server is stopped")
        self.status_label.pack(pady=10)

        self.server_thread = None

    def start_server(self):
        if not self.server_thread:
            self.server_thread = ServerThread()
            self.server_thread.start()
            self.start_button.config(state=tk.DISABLED)
            self.stop_button.config(state=tk.NORMAL)
            self.status_label.config(text="Server is running")
            webbrowser.open("http://localhost:5000")

    def stop_server(self):
        if self.server_thread:
            # This will require manually stopping the Flask server process
            messagebox.showinfo("Information", "Please stop the server manually by closing the terminal window.")
            self.server_thread = None
            self.start_button.config(state=tk.NORMAL)
            self.stop_button.config(state=tk.DISABLED)
            self.status_label.config(text="Server is stopped")

if __name__ == "__main__":
    root = tk.Tk()
    app = FileTransferApp(root)
    root.mainloop()
