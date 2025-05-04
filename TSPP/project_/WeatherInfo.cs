﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Погодка
{
    public class WeatherInfo
    {
        public int Day { get; set; }
        public int Month { get; set; }
        public double Temperature { get; set; }
        public string Precipitation { get; set; }
        public int Pressure { get; set; }

        // Додаткове поле для виводу у форматі "день.місяць"
        public string Date => $"{Day:D2}.{Month:D2}";
    }
}
