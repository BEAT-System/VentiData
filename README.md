# VentiData

is a simple exchange format for end-end- communnication in the BEAT-Project


## Data

| Name | Description  | Unit | Initial | Min | Max | Type |
|------|--------------|:----:|:-------:|:---:|:---:|:----:|
| time_high   | higher bytes of the time | / | 0 | 0 | 1024 | int16_t |
| time_low   | lower bytes of the time | / | 0 | 0 | 1024 | int16_t |
| id   | ID des Reglers | / | 7 | 1 | 10000 | int16_t |
| contr_kp | PID Reglerparameter - Kp Proportionalfaktor | 1/bar  | 56 | 1 | 1024 | int16_t |
| contr_tn | PID Reglerparameter - Nachstellzeit | ms | 304 | 1 | 1024 | int16_t |
| contr_tv| APID Reglerparameter - Vorstellzeit | ms | 37 | 1 | 1024 | int16_t |
| flow_c | Aktueller Flow-Istwert für Plotdarstellung | slpm | 0 | 1 | 1024 | int16_t |
| vol_c| Aktueller Volumen-Istwert für Plotdarstellung | ml | 0 | 1 | 1024 | int16_t |
| p_c | Aktueller Druck-Istwert für Plotdarstellung | mBar | 0 | 1 | 1024 | int16_t |
| p_set| Aktueller Druck-Sollwert für Plotdarstellung | mBar | 0 | 1 | 1024 | int16_t |
| contr_mode | Momentaner Controller Betriebsmodus | / | 0 | 0 | 10 | int16_t |
| panel_mode | Momentaner Panel Betriebsmodus | / | 0 | 0 | 10 | int16_t |
| bpm    | Beatmungsfrequenz (Beatmungen pro Minute) | 1/min | 8  | 1 | 30 | int16_t |
| p_insp | Inspirationsdruck Sollwert  | mBar | 20  | 1 | 100 | int16_t |
| p_exp  | Exspirationsdruck Sollwert  | mBar | 6  | 1 | 20 | int16_t |
| v_insp | Anhand der Flowrate ermitteltes Inspirationsvolumen („flow ist“ über der Zeit integriert in der Inspirationsphase) | ml  | / | 0 | 10 | int16_t |
| v_exp  | Anhand der Flowrate ermitteltes Exspirationsvolumen („flow ist“ über der Zeit integriert in der Exspirationsphase) | ml  | / | 0 | 10 | int16_t |
| dvol   | Grenzwerte prozentuale Abweichung zwischen Inspirationsvolumen und Exspirationsvolumen | % | 10 | 1 | 100 | int16_t |
| duty   | Verhältnis zwischen Inspirations- und Exspirationszeit | % | 10 | 1 | 100 | int16_t |
| dt_rise| Zeittoleranz um Inspirationsdruck aufzubauen, liegt p_ist nach Überschreiten von dt_rise nicht im Bereich p_ins ± dp_ins wird Alarm ausgelöst | % | 10 | 1 | 100 | int16_t |
| dp_insp| AToleranzschlauch für den Inspirationsdruck | % | 10 | 1 | 100 | int16_t |
| dp_exp | Toleranzschlauch für den Exspirationsdruck | % | 10 | 1 | 100 | int16_t |
| dt_fall | Zeittoleranz um Exspirationsdruck aufzubauen, liegt p_ist nach Überschreiten von dt_rise nicht im Bereich p_exp ± dp_exp wird Alarm ausgelöst | % | 10 | 1 | 100 | int16_t |
