using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TableGenerator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            previewPicture.Image = new Bitmap(previewPicture.Width, previewPicture.Height);
            Bitmap bm = new Bitmap(16, 16);
            Graphics g2 = Graphics.FromImage(bm);
            Graphics g = Graphics.FromImage(previewPicture.Image);
            String resultString = "";
            int shift = previewPicture.Height / 16;
            g.FillRectangle(Brushes.Black, new Rectangle(0, 0, previewPicture.Width, previewPicture.Height));
            g.DrawString(inputText.Text, new Font("Calibri", 50), Brushes.White, new PointF(0,0));
            g2.FillRectangle(Brushes.Black, new Rectangle(0, 0, 16, 16));
            g2.DrawString(inputText.Text, new Font("Calibri", 10), Brushes.White, new PointF(0, 0));

            Console.WriteLine("width = " + previewPicture.Width + " height = " + previewPicture.Height + " shift = " + shift);
            Console.WriteLine(Color.FromArgb(255, 0, 0, 0));
            for (int i = 0; i < 16; i++)
            {
                resultString += "{0b";
                for (int j = 0; j < 8; j++)
                {
                    Console.WriteLine("pt" + i * shift + ", " + j * shift + " = \t" + bm.GetPixel(i, j));
                    if (!bm.GetPixel(i, j).Equals(Color.FromArgb(255, 0, 0, 0)))
                        resultString += "1";
                    else
                        resultString += "0";
                }
                resultString += ", 0b";
                for (int j = 8; j < 16; j++) { 
                    if (!bm.GetPixel(i, j).Equals(Color.FromArgb(255, 0, 0, 0)))
                        resultString += "1";
                 else
                        resultString += "0";
                }
                resultString += "},\r\n";

            }
            resultBox.Text = resultString;
            resultBox.Enabled = true;
        }

 
    

        private void Form1_Shown(object sender, EventArgs e)
        {

        }
    }
}
