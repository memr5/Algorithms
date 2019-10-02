package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestHammingWeight(t *testing.T) {
	assert.Equal(t, HammingWeight(0x1234567890), 15)
	assert.Equal(t, HammingWeight(0xabcdef), 17)
	assert.Equal(t, HammingWeight(0xabcdef1234567890), 32)
}
