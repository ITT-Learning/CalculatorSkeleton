#include <cstring>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ExpressionFactory.h"
#include "ExpressionSerializer.h"
#include "Expression_generated.h"

/**
 * @brief tests flatbuffer serialization by ensuring that the data extracted from the serialized buffer is the same as
 * the data used to produce that buffer
 */
TEST(ExpressionSerializerIntTestSuite, WhenSerializeIsCalled_ThenTheReturnedFlatBufferIsCorrectAndCanBeDeserializedIntoAnEquivalentExpression)
{
    std::string expressionString{"-a + 3 * 12 - b / (11 + 99) --4"};
    auto expression = calculator::expression::ExpressionFactory<int>::parseFromComplexString(expressionString);
    auto builtBuffer = calculator::expression::ExpressionSerializer<int>::serialize(*expression);

    // simulate sending and receiving over a network or saving and loading a file or etc, etc...
    calculator::expression::ExpressionSerializer<int>::ExpressionBuffer receivedBuffer{builtBuffer.data(), builtBuffer.data() + builtBuffer.size()};

    auto receivedExpression = calculator::expression::ExpressionSerializer<int>::deserialize(receivedBuffer);
    EXPECT_EQ(expression->toString(), receivedExpression->toString());
}

/**
 * @brief tests flatbuffer serialization by ensuring that the data extracted from the serialized buffer is the same as
 * the data used to produce that buffer
 */
TEST(ExpressionSerializerDoubleTestSuite, WhenSerializeIsCalled_ThenTheReturnedFlatBufferIsCorrectAndCanBeDeserializedIntoAnEquivalentExpression)
{
    std::string expressionString{"-a + 3 * 12 - b / (11 + 99) --4"};
    auto expression = calculator::expression::ExpressionFactory<double>::parseFromComplexString(expressionString);
    auto builtBuffer = calculator::expression::ExpressionSerializer<double>::serialize(*expression);

    // simulate sending and receiving over a network or saving and loading a file or etc, etc...
    calculator::expression::ExpressionSerializer<double>::ExpressionBuffer receivedBuffer{builtBuffer.data(), builtBuffer.data() + builtBuffer.size()};

    auto receivedExpression = calculator::expression::ExpressionSerializer<double>::deserialize(receivedBuffer);
    EXPECT_EQ(expression->toString(), receivedExpression->toString());
}