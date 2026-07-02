import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import (
    UNIT_KILOWATT_HOUR,
    UNIT_WATT,
    UNIT_VOLT,
    UNIT_AMPERE,
    DEVICE_CLASS_ENERGY,
    DEVICE_CLASS_POWER,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    STATE_CLASS_MEASUREMENT,
    STATE_CLASS_TOTAL_INCREASING,
)

from . import P1Reader

# Sensor definitions
energy_import = sensor.sensor_schema(
    unit_of_measurement=UNIT_KILOWATT_HOUR,
    accuracy_decimals=3,
    device_class=DEVICE_CLASS_ENERGY,
    state_class=STATE_CLASS_TOTAL_INCREASING,
)

power_import = sensor.sensor_schema(
    unit_of_measurement=UNIT_WATT,
    accuracy_decimals=0,
    device_class=DEVICE_CLASS_POWER,
    state_class=STATE_CLASS_MEASUREMENT,
)

voltage_l1 = sensor.sensor_schema(
    unit_of_measurement=UNIT_VOLT,
    accuracy_decimals=1,
    device_class=DEVICE_CLASS_VOLTAGE,
    state_class=STATE_CLASS_MEASUREMENT,
)

voltage_l2 = sensor.sensor_schema(
    unit_of_measurement=UNIT_VOLT,
    accuracy_decimals=1,
    device_class=DEVICE_CLASS_VOLTAGE,
    state_class=STATE_CLASS_MEASUREMENT,
)

voltage_l3 = sensor.sensor_schema(
    unit_of_measurement=UNIT_VOLT,
    accuracy_decimals=1,
    device_class=DEVICE_CLASS_VOLTAGE,
    state_class=STATE_CLASS_MEASUREMENT,
)

current_l1 = sensor.sensor_schema(
    unit_of_measurement=UNIT_AMPERE,
    accuracy_decimals=1,
    device_class=DEVICE_CLASS_CURRENT,
    state_class=STATE_CLASS_MEASUREMENT,
)

current_l2 = sensor.sensor_schema(
    unit_of_measurement=UNIT_AMPERE,
    accuracy_decimals=1,
    device_class=DEVICE_CLASS_CURRENT,
    state_class=STATE_CLASS_MEASUREMENT,
)

current_l3 = sensor.sensor_schema(
    unit_of_measurement=UNIT_AMPERE,
    accuracy_decimals=1,
    device_class=DEVICE_CLASS_CURRENT,
    state_class=STATE_CLASS_MEASUREMENT,
)

power_l1 = sensor.sensor_schema(
    unit_of_measurement=UNIT_WATT,
    accuracy_decimals=0,
    device_class=DEVICE_CLASS_POWER,
    state_class=STATE_CLASS_MEASUREMENT,
)

power_l2 = sensor.sensor_schema(
    unit_of_measurement=UNIT_WATT,
    accuracy_decimals=0,
    device_class=DEVICE_CLASS_POWER,
    state_class=STATE_CLASS_MEASUREMENT,
)

power_l3 = sensor.sensor_schema(
    unit_of_measurement=UNIT_WATT,
    accuracy_decimals=0,
    device_class=DEVICE_CLASS_POWER,
    state_class=STATE_CLASS_MEASUREMENT,
)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.use_id(P1Reader),

    cv.Optional("energy_import"): energy_import,
    cv.Optional("power_import"): power_import,

    cv.Optional("voltage_l1"): voltage_l1,
    cv.Optional("voltage_l2"): voltage_l2,
    cv.Optional("voltage_l3"): voltage_l3,

    cv.Optional("current_l1"): current_l1,
    cv.Optional("current_l2"): current_l2,
    cv.Optional("current_l3"): current_l3,

    cv.Optional("power_l1"): power_l1,
    cv.Optional("power_l2"): power_l2,
    cv.Optional("power_l3"): power_l3,
})

def to_code(config):
    reader = yield cg.get_variable(config[cv.GenerateID()])

    if "energy_import" in config:
        sens = yield sensor.new_sensor(config["energy_import"])
        cg.add(reader.set_energy_import_sensor(sens))

    if "power_import" in config:
        sens = yield sensor.new_sensor(config["power_import"])
        cg.add(reader.set_power_import_sensor(sens))

    if "voltage_l1" in config:
        sens = yield sensor.new_sensor(config["voltage_l1"])
        cg.add(reader.set_voltage_l1_sensor(sens))

    if "voltage_l2" in config:
        sens = yield sensor.new_sensor(config["voltage_l2"])
        cg.add(reader.set_voltage_l2_sensor(sens))

    if "voltage_l3" in config:
        sens = yield sensor.new_sensor(config["voltage_l3"])
        cg.add(reader.set_voltage_l3_sensor(sens))

    if "current_l1" in config:
        sens = yield sensor.new_sensor(config["current_l1"])
        cg.add(reader.set_current_l1_sensor(sens))

    if "current_l2" in config:
        sens = yield sensor.new_sensor(config["current_l2"])
        cg.add(reader.set_current_l2_sensor(sens))

    if "current_l3" in config:
        sens = yield sensor.new_sensor(config["current_l3"])
        cg.add(reader.set_current_l3_sensor(sens))

    if "power_l1" in config:
        sens = yield sensor.new_sensor(config["power_l1"])
        cg.add(reader.set_power_l1_sensor(sens))

    if "power_l2" in config:
        sens = yield sensor.new_sensor(config["power_l2"])
        cg.add(reader.set_power_l2_sensor(sens))

    if "power_l3" in config:
        sens = yield sensor.new_sensor(config["power_l3"])
        cg.add(reader.set_power_l3_sensor(sens))
