QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    include/httplib/httplib.h \
    include/nlohmann/adl_serializer.hpp \
    include/nlohmann/byte_container_with_subtype.hpp \
    include/nlohmann/detail/boolean_operators.hpp \
    include/nlohmann/detail/conversions/from_json.hpp \
    include/nlohmann/detail/conversions/to_chars.hpp \
    include/nlohmann/detail/conversions/to_json.hpp \
    include/nlohmann/detail/exceptions.hpp \
    include/nlohmann/detail/input/binary_reader.hpp \
    include/nlohmann/detail/input/input_adapters.hpp \
    include/nlohmann/detail/input/json_sax.hpp \
    include/nlohmann/detail/input/lexer.hpp \
    include/nlohmann/detail/input/parser.hpp \
    include/nlohmann/detail/input/position_t.hpp \
    include/nlohmann/detail/iterators/internal_iterator.hpp \
    include/nlohmann/detail/iterators/iter_impl.hpp \
    include/nlohmann/detail/iterators/iteration_proxy.hpp \
    include/nlohmann/detail/iterators/iterator_traits.hpp \
    include/nlohmann/detail/iterators/json_reverse_iterator.hpp \
    include/nlohmann/detail/iterators/primitive_iterator.hpp \
    include/nlohmann/detail/json_pointer.hpp \
    include/nlohmann/detail/json_ref.hpp \
    include/nlohmann/detail/macro_scope.hpp \
    include/nlohmann/detail/macro_unscope.hpp \
    include/nlohmann/detail/meta/cpp_future.hpp \
    include/nlohmann/detail/meta/detected.hpp \
    include/nlohmann/detail/meta/is_sax.hpp \
    include/nlohmann/detail/meta/type_traits.hpp \
    include/nlohmann/detail/meta/void_t.hpp \
    include/nlohmann/detail/output/binary_writer.hpp \
    include/nlohmann/detail/output/output_adapters.hpp \
    include/nlohmann/detail/output/serializer.hpp \
    include/nlohmann/detail/value_t.hpp \
    include/nlohmann/json.hpp \
    include/nlohmann/json_fwd.hpp \
    include/nlohmann/thirdparty/hedley/hedley.hpp \
    include/nlohmann/thirdparty/hedley/hedley_undef.hpp

DISTFILES += \
  informer_template.html
