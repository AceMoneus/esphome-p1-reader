# P1 Reader – ESPHome Slimmelezer+ Component (Aidon 6534)

This project was created because I ran into a fundamental limitation in ESPHome Device Builder, the new ESPHome integration inside Home Assistant.
Unlike the old ESPHome Add-on, I ran into problems with ESPHome Device Builder and couldn't load local custom components from the Home Assistant filesystem (such as /config/esphome/components/).
My setup is based on the infamous Aidon 6534 (6442SE RF500) from Tekniska Verken.

This project is based on and inspired by the original Slimmelezer+ work by P. Svanström.
https://github.com/psvanstrom/esphome-p1reader

 Installation (Home Assistant ESPHome Device Builder)

Add the following to your ESPHome YAML:

```yaml
external_components:
  - source: github://AceMoneus/esphome-p1-reader
    components: [p1_reader]

