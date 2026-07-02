import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID, CONF_UART_ID

AUTO_LOAD = ["uart"]

p1_reader_ns = cg.esphome_ns.namespace("p1_reader")
P1Reader = p1_reader_ns.class_("P1Reader", cg.Component, uart.UARTDevice)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(P1Reader),
    cv.Required(CONF_UART_ID): cv.use_id(uart.UARTComponent),
    cv.Optional("protocol", default="hdlc"): cv.one_of("hdlc", "plain"),
})

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var)
    uart_component = yield cg.get_variable(config[CONF_UART_ID])
    cg.add(var.set_uart(uart_component))
    cg.add(var.set_protocol(config["protocol"]))
