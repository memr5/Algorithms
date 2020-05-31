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

func TestHammingDistance(t *testing.T) {
	assert.Equal(t, HammingDistance(0x1234567890, 0xabcdef), 24)
	assert.Equal(t, HammingDistance(0xabcdef, 0xabcdef1234567890), 41)
	assert.Equal(t, HammingDistance(0xabcdef1234567890, 0x1234567890), 17)
}
