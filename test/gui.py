"""A simple graphical calculator using Tkinter."""

import tkinter as tk
from tkinter import messagebox, ttk


def calculate():
    """Perform the selected calculation and display the result."""
    if command_entry.get().strip() == "000":
        window.destroy()
        return

    try:
        first_number = float(first_entry.get())
        second_number = float(second_entry.get())
    except ValueError:
        messagebox.showerror("Invalid input", "Enter a number in both number fields.")
        return

    operation = operation_box.get()

    if operation == "+":
        answer = first_number + second_number
    elif operation == "-":
        answer = first_number - second_number
    elif operation == "*":
        answer = first_number * second_number
    elif operation == "/":
        if second_number == 0:
            messagebox.showerror("Invalid operation", "Cannot divide by zero.")
            return
        answer = first_number / second_number
    else:
        messagebox.showerror("Invalid operation", "Select an operation.")
        return

    result_label.config(text=f"Result: {answer:g}")
    first_entry.delete(0, tk.END)
    second_entry.delete(0, tk.END)
    command_entry.delete(0, tk.END)
    operation_box.set("+")
    first_entry.focus()


window = tk.Tk()
window.title("Simple Calculator")
window.resizable(False, False)
window.configure(bg="#dbeafe")

style = ttk.Style()
style.configure("Main.TFrame", background="#dbeafe")
style.configure("Title.TLabel", background="#dbeafe", foreground="#1e3a8a")
style.configure("TLabel", background="#dbeafe", foreground="#172554")
style.configure("TButton", background="#2563eb", foreground="#ffffff", padding=6)
style.map("TButton", background=[("active", "#1d4ed8")])
style.configure("Result.TLabel", background="#bfdbfe", foreground="#1e3a8a", padding=8)

main_frame = ttk.Frame(window, padding=16, style="Main.TFrame")
main_frame.grid()

ttk.Label(main_frame, text="Simple Calculator", style="Title.TLabel", font=("Arial", 16, "bold")).grid(
    row=0, column=0, columnspan=2, pady=(0, 10)
)

ttk.Label(main_frame, text="First number:").grid(row=1, column=0, padx=5, pady=5)
first_entry = ttk.Entry(main_frame, width=15)
first_entry.grid(row=1, column=1, padx=5, pady=5)

ttk.Label(main_frame, text="Operation:").grid(row=2, column=0, padx=5, pady=5)
operation_box = ttk.Combobox(main_frame, values=("+", "-", "*", "/"), width=12, state="readonly")
operation_box.set("+")
operation_box.grid(row=2, column=1, padx=5, pady=5)

ttk.Label(main_frame, text="Second number:").grid(row=3, column=0, padx=5, pady=5)
second_entry = ttk.Entry(main_frame, width=15)
second_entry.grid(row=3, column=1, padx=5, pady=5)

ttk.Label(main_frame, text="Command (type 000 to exit):").grid(
    row=4, column=0, padx=5, pady=5
)
command_entry = ttk.Entry(main_frame, width=15)
command_entry.grid(row=4, column=1, padx=5, pady=5)

ttk.Button(main_frame, text="Calculate", command=calculate).grid(
    row=5, column=0, columnspan=2, pady=10
)
result_label = ttk.Label(main_frame, text="Result: ", style="Result.TLabel")
result_label.grid(row=6, column=0, columnspan=2, pady=5)

window.bind("<Return>", lambda event: calculate())
first_entry.focus()
window.mainloop()
