namespace _0207_forms
{
	partial class Form1
	{
		/// <summary>
		///  Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		///  Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		///  Required method for Designer support - do not modify
		///  the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			checkBox1 = new CheckBox();
			label1 = new Label();
			label2 = new Label();
			radioButton1 = new RadioButton();
			SuspendLayout();
			// 
			// checkBox1
			// 
			checkBox1.AutoSize = true;
			checkBox1.Location = new Point(432, 119);
			checkBox1.Name = "checkBox1";
			checkBox1.Size = new Size(103, 24);
			checkBox1.TabIndex = 0;
			checkBox1.Text = "checkBox1";
			checkBox1.UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			label1.Location = new Point(0, 0);
			label1.Name = "label1";
			label1.Size = new Size(100, 23);
			label1.TabIndex = 0;
			// 
			// label2
			// 
			label2.AutoSize = true;
			label2.Location = new Point(463, 216);
			label2.Name = "label2";
			label2.Size = new Size(50, 20);
			label2.TabIndex = 1;
			label2.Text = "label2";
			// 
			// radioButton1
			// 
			radioButton1.AutoSize = true;
			radioButton1.Location = new Point(612, 327);
			radioButton1.Name = "radioButton1";
			radioButton1.Size = new Size(119, 24);
			radioButton1.TabIndex = 2;
			radioButton1.TabStop = true;
			radioButton1.Text = "radioButton1";
			radioButton1.UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			AutoScaleDimensions = new SizeF(9F, 20F);
			AutoScaleMode = AutoScaleMode.Font;
			ClientSize = new Size(800, 450);
			Controls.Add(radioButton1);
			Controls.Add(label2);
			Controls.Add(label1);
			Controls.Add(checkBox1);
			Name = "Form1";
			Text = "Form1";
			Load += Form1_Load;
			ResumeLayout(false);
			PerformLayout();
		}

		#endregion

		private CheckBox checkBox1;
		private Label label1;
		private Label label2;
		private RadioButton radioButton1;
	}
}
